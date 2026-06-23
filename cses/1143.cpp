/**
 * Contest : CSES Problem Set
 * Problem : 1143 - Hotel Queries
 * Link    : https://cses.fi/problemset/task/1143
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
     tree[no] = v[l];
     return;
    }
    int m = l + (r-l)/2;

    build(2*no, l, m);
    build(2*no + 1, m + 1, r);
    tree[no] = max(tree[2*no], tree[2*no + 1]);
  }


  int query(int no, int l, int r, int qi) {
    if (l == r) {
      if (tree[no] < qi) return 0;
      tree[no] -= qi;
      return l;
    }
    int m = l + (r-l)/2;

    if (tree[2*no] >= qi) {
      int idx = query(2*no, l, m, qi);
      if (idx != 0) tree[no] = max(tree[2*no], tree[2*no + 1]);
      return idx;
    }
    else if (tree[2*no+1] >= qi) {
      int idx = query(2*no + 1, m+1, r, qi);
      if (idx != 0) tree[no] = max(tree[2*no], tree[2*no + 1]);
      return idx;
    }
    else return 0;
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
    int qi; cin >> qi;

    cout << st.query(1, 1, n, qi) << " \n"[!q];
  }

  return 0;
}
