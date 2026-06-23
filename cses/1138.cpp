/**
 * Contest : CSES Problem Set
 * Problem : 1138 - Path Queries
 * Link    : https://cses.fi/problemset/task/1138
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<ll>> tree;
vector<ll> subsize, pos, order;
vector<ll> sum;

struct SegTreeLazy {
  vector<ll> tree, lazy, v;
  ll n;

  SegTreeLazy(ll n) : n(n) {
    tree.resize(4*n, 0);
    lazy.resize(4*n, 0);
    v.resize(n + 1, 0);
  }

  ll join(ll a, ll b) {
    return a + b;
  }

  void build(ll no, ll l, ll r) {
    if (l == r) { tree[no] = v[l]; return; }
    ll m = l + (r-l)/2;

    build(2*no, l, m);
    build(2*no + 1, m + 1, r);

    tree[no] = join(tree[2*no], tree[2*no + 1]);
  }

  void pushDown(ll no, ll l, ll r) {
    if (lazy[no] == 0) return;
    ll m = l + (r-l)/2;

    tree[2*no] += lazy[no] * (m-l + 1);
    tree[2*no + 1] += lazy[no] * (r - m);

    lazy[2*no] += lazy[no];
    lazy[2*no + 1] += lazy[no];
    lazy[no] = 0;
  }

  void update(ll no, ll l, ll r, ll ql, ll qr, ll val) {
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr) {
      tree[no] += val * (r - l + 1);
      lazy[no] += val;
      return;
    }
    pushDown(no, l, r);
    ll m = l + (r-l)/2;

    update(2*no, l, m, ql, qr, val);
    update(2*no + 1, m + 1, r, ql, qr, val);

    tree[no] = join(tree[2*no], tree[2*no + 1]);
  }

  ll query(ll no, ll l, ll r, ll pos) {
    if (l == r)
      return tree[no];
    pushDown(no, l, r);

    ll m = l + (r-l)/2;

    if (pos <= m) return query(2*no, l, m, pos);
    else return query(2*no + 1, m + 1, r, pos);
  }
};

void dfs(ll u, ll p) {
  for (auto& v : tree[u])
    if (v != p) {
      sum[v] += sum[u];
      dfs(v,u);
      subsize[u] += subsize[v]+1;
    }
  order.push_back(u);
}

int main() {
  fastio

  ll n, q;
  cin >> n >> q;

  tree.assign(n+1, {});
  subsize.assign(n+1,0);
  pos.assign(n+1, 0);
  sum.assign(n+1, 0);

  vector<ll> v(n+1);
  for (ll i = 1; i <= n; ++i) { cin >> v[i]; sum[i] = v[i]; }

  for (ll i = 2; i <= n; ++i) {
    ll a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  dfs(1, 1);
  reverse(order.begin(), order.end());
  vector<ll> pos(n+1);
  for (ll i = 1; i <= n; ++i) pos[order[i-1]] = i;

  SegTreeLazy st(n+1);
  for (ll i = 1; i <= n; ++i) st.v[i] = sum[order[i-1]];
  st.build(1, 1, n);

  while (q--) {
    ll op, s;
    cin >> op >> s;

    auto s_pos = pos[s];
    if (op == 1) {
      ll x; cin >> x;
      st.update(1, 1, n, s_pos, s_pos+subsize[s], x-v[s]);
      v[s] = x;
    }
    else
      cout << st.query(1, 1, n, s_pos) << '\n';
  }

  return 0;
}