/**
 * Contest : CSES Problem Set
 * Problem : 1651 - Range Update Queries
 * Link    : https://cses.fi/problemset/task/1651/
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

struct SegTreeLazy {
  vector<ll> tree, lazy;
  vector<ll> v;
  ll n;

  SegTreeLazy(ll n) : n(n) {
    tree.assign(4*n, 0);
    lazy.assign(4*n, 0);
    v.assign(n, 0);
  }

  void build(ll no, ll l, ll r) {
    if (l == r) {
      tree[no] = v[l];
      return;
    }
    ll m = l+(r-l)/2;

    build(2*no, l, m);
    build(2*no + 1, m + 1, r);
    tree[no] = tree[2*no] + tree[2*no + 1];
  }

  void pushDown(ll no, ll l, ll r) {
    if (lazy[no] == 0) return;
    ll m = l+(r-l)/2;

    tree[2*no] += lazy[no] * (m - l + 1);
    tree[2*no + 1] += lazy[no] * (r - m);

    lazy[2*no] += lazy[no];
    lazy[2*no + 1] += lazy[no];
    lazy[no] = 0;
  }

  void update(ll no, ll l, ll r, ll ql, ll qr, ll val) {
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr) {
      tree[no] += val * (r-l+1);
      lazy[no] += val;
      return;
    }
    pushDown(no, l, r);

    ll m = l+(r-l)/2;
    update(2*no, l, m, ql, qr, val);
    update(2*no + 1, m + 1, r, ql, qr, val);
    tree[no] = tree[2*no] + tree[2*no + 1];
  }

  ll query(ll no, ll l, ll r, ll ql, ll qr) {
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return tree[no];
    pushDown(no, l, r);

    ll m = l+(r-l)/2;
    return query(2*no, l, m, ql, qr) + query(2*no + 1, m + 1, r, ql, qr);
  }
};

int main() {
  fastio

  int n, q;
  cin >> n >> q;

  SegTreeLazy st(n);
  for (int i = 1; i <= n; ++i) {
    ll x; cin >> x;
    st.v[i] = x;
  }
  st.build(1, 1, n);

  while (q--) {
    ll op; cin >> op;
    if (op == 1) {
      ll a, b, u;
      cin >> a >> b >> u;
      st.update(1, 1, n, a, b, u);
    }
    else {
      ll k; cin >> k;
      cout << st.query(1, 1, n, k, k) << '\n';
    }
  }

  return 0;
}