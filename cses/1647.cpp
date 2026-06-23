/**
 * Contest : CSES Problem Set
 * Problem : 1647 - Static Range Minimum Queries
 * Link    : https://cses.fi/problemset/task/1647
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

struct SegTree {
  vector <int> v, tree;
  int n;

  SegTree(int n) : n(n) {
    tree.assign(4*n, 1e9);
    v.resize(n+1);
  }

  void build(int no, int l, int r) {
    if (l == r) {
     tree[no] = v[l];
     return;
    }
    int m = l + (r-l)/2;

    build(2 * no, l, m);
    build(2 * no + 1, m + 1, r);
    tree[no] = min(tree[2 * no], tree[2 * no + 1]);
  }
  void update(int no, int l, int r, int pos, int val) {
    if (l == r) {
      tree[no] = val;
      return;
    }
    int m = l + (r-l)/2;
    if (pos <= m) update(2 * no, l, m, pos, val);
    else update(2 * no + 1, m + 1, r, pos, val);

    tree[no] = min(tree[2 * no], tree[2 * no + 1]);
  }

  int query(int no, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 1e9;
    if (l >= ql && r <= qr) return tree[no];
    int m = l + (r-l)/2;

    return min(query(2 * no, l, m, ql, qr), query(2 * no + 1, m + 1, r, ql, qr));
  }
};

int main() {
  fastio

  int n, q;
  cin >> n >> q;

  SegTree st(n);
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    st.v[i] = x;
  }
  st.build(1, 1, n);

  while (q--) {
    int a, b;
    cin >> a >> b;

    cout << st.query(1, 1, n, a, b) << '\n';
  }

  return 0;
}
