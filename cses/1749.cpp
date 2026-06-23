/**
 * Contest : CSES Problem Set
 * Problem : 1749 - List Removals
 * Link    : https://cses.fi/problemset/task/1749
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
    tree.assign(4*n, 0);
    v.assign(n, 0);
  }

  void build(int no, int l, int r) {
    if (l == r) {
     tree[no] = 1;
     return;
    }
    int m = l + (r-l)/2;

    build(2*no, l, m);
    build(2*no + 1, m + 1, r);
    tree[no] = tree[2*no] + tree[2*no + 1];
  }

  int query(int no, int l, int r, int pos) {
    if (l == r) {
      auto val = v[l];
      tree[no] = v[l] = 0;
      return val;
    }
    int m = l + (r-l)/2, val;

    if (tree[2*no] >= pos)
      val = query(2*no, l, m, pos);
    else
      val = query(2*no + 1, m+1, r, pos-tree[2*no]);
    tree[no] = tree[2*no] + tree[2*no + 1];
    return val;
  }
};

int main() {
  fastio

  int n;
  cin >> n;

  SegTree st(n);
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    st.v[i] = x;
  }
  st.build(1, 1, n);

  for (int i = 0; i < n; ++i) {
    int pos; cin >> pos;
    cout << st.query(1, 1, n, pos) << " \n"[i==n-1];
  }

  return 0;
}
