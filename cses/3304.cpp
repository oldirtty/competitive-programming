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
    int cnt = 1, max_h = 0;

    Node(int cnt, int h) : cnt(cnt), max_h(h) {}
  };

  vector<int> v;
  vector<Node> tree;
  int n;

  SegTree(int n) : n(n) {
    v.assign(4*n, 0);
    tree.assign(4*n, Node(1,0));
  }

  Node join(const Node& a, const Node& b) {
    Node ab(a.cnt, 0);
    if (a.max_h < b.max_h) ab.cnt += b.cnt;
    ab.max_h = max(a.max_h, b.max_h);
    return ab;
  }

  void build(int no, int l, int r) {
    if (l == r) {
      tree[no] = Node(1,v[l]);
      return;
    }
    int m = l + (r-l)/2;
    build(2*no, l, m);
    build(2*no + 1, m + 1, r);

    tree[no] = join(tree[2*no], tree[2*no + 1]);
  }

  Node query(int no, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return Node(0,0);
    if (l >= ql && r <= qr) return tree[no];
    int m = l + (r-l)/2;

    return join(query(2*no, l, m, ql, qr), query(2*no + 1, m + 1, r, ql, qr));
  }
};

int main() {
  fastio

  /*
   4  1  2  2  3
  +4 -3 +1  0 +1

  Quantas vezes de [l..r] o valor
  de max atualiza




  */

  return 0;
}