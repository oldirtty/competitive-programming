/**
 * Contest : CSES Problem Set
 * Problem : 3304 - Visible Buildings Queries
 * Link    : https://cses.fi/problemset/task/3304
 * Time    : O(???)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

struct SegTree {
  struct Node {
    int cnt = 0, max_h = 0;
  };

  vector<int> v;
  vector<Node> tree;
  int n;

  SegTree(int n) : n(n) {
    v.assign(4*n, 0);
    tree.assign(4*n, Node{});
  }

  Node join(const Node& a, const Node& b) {
    Node ab{a.cnt, 0};
    if (a.max_h < b.max_h) ab.cnt += b.cnt;
    ab.max_h = max(a.max_h, b.max_h);
    return ab;
  }

  void build(int no, int l, int r) {
    if (l == r) {
      tree[no] = Node{1,v[l]};
      return;
    }
    int m = l + (r-l)/2;
    build(2*no, l, m);
    build(2*no + 1, m + 1, r);

    tree[no] = join(tree[2*no], tree[2*no + 1]);
  }

  Node query(int no, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return Node{0,0};
    if (l >= ql && r <= qr) {
      fprintf(stderr, "range[%i..%i] | tree[%i] = { %i , %i }\n", l, r, no,  tree[no].cnt, tree[no].max_h);
      return tree[no];
    }
    int m = l + (r-l)/2;

    return join(query(2*no, l, m, ql, qr), query(2*no + 1, m + 1, r, ql, qr));
  }
};

int main() {
  fastio

  int n, q;
  cin >> n >> q;

  SegTree st(n);
  for (int i = 1; i <= n; ++i) cin >> st.v[i];
  st.build(1, 1, n);

  for (int i = 0; i < st.tree.size(); ++i) {
    cout << i << ": " << st.tree[i].cnt << ' ' << st.tree[i].max_h << endl;
  }

  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << st.query(1, 1, n, a, b).cnt << '\n';
    cerr << '\n';
  }

  return 0;
}