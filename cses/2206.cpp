/**
 * Contest : CSES Problem Set
 * Problem : 2206 - Pizzeria Queries
 * Link    : https://cses.fi/problemset/task/2206
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

struct SegTree {
  vector<ll> v, tree;
  const ll INF = 1e18;
  ll n;

  SegTree(ll n) : n(n) {
    tree.assign(4*n, INF);
    v.assign(n+1, INF);
  }

  ll join(ll a, ll b) {
    return min(a,b);
  }

  void build(ll no, ll l, ll r) {
    if (l == r) {
      tree[no] = v[l];
      return;
    }
    ll m = l + (r-l)/2;
    build(2*no, l, m);
    build(2*no + 1, m + 1, r);

    tree[no] = join(tree[2*no], tree[2*no + 1]);
  }

  void update(ll no, ll l, ll r, ll pos, ll val) {
    if (l == r) {
      tree[no] = val;
      return;
    }
    ll m = l + (r-l)/2;
    if (pos <= m) update(2*no, l, m, pos, val);
    else update(2*no + 1, m + 1, r, pos, val);

    tree[no] = join(tree[2*no], tree[2*no + 1]);
  }

  ll query(ll no, ll l, ll r, ll ql, ll qr) {
    if (l > qr || r < ql) return INF;
    if (l >= ql && r <= qr) return tree[no];
    ll m = l + (r-l)/2;

    return join(query(2*no, l, m, ql, qr), query(2*no + 1, m + 1, r, ql, qr));
  }
};

int main() {
  fastio

  ll n, q;
  cin >> n >> q;
  vector<ll> v(n+1);
  for (ll i = 1; i <= n; ++i) cin >> v[i];

  SegTree left(n), right(n);
  for (ll i = 1; i <= n; ++i) {
    left.v[i] = v[i]-i;
    right.v[i] = v[i]+i;
  }
  left.build(1, 1, n);
  right.build(1, 1, n);

  while (q--) {
    ll op, k;
    cin >> op >> k;

    if (op == 1) {
      ll x; cin >> x;
      left.update(1, 1, n, k, x-k);
      right.update(1, 1, n, k, x+k);
    }
    else {
      cout << min(
        left.query(1, 1, n, 1, k) + k,
        right.query(1, 1, n, k, n) - k
      ) << '\n';
    }
  }

  return 0;
}