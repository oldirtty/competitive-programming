/**
 * Contest : CSES Problem Set
 * Problem : 1144 - Salary Queries
 * Link    : https://cses.fi/problemset/task/1144
 * Time    : O(N * logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

struct Compress {
  vector<int> c;
  void add(int x) { c.push_back(x); }
  void build() {
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
  }
  int get(int x) { return upper_bound(c.begin(), c.end(), x) - c.begin(); }
  int size() { return c.size(); }
};

struct FenwickTree {
  vector<int> v;
  int n;

  FenwickTree(int n) : n(n), v(n+1, 0) {}

  int sum(int r) {
    int ret = 0;
    for (; r > 0; r -= r & (-r)) ret += v[r];
    return ret;
  }

  int sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }

  void add(int idx, int delta) {
    for (; idx <= n; idx += idx & (-idx)) v[idx] += delta;
  }
};

int main() {
  fastio

  int n, q;
  cin >> n >> q;

  Compress coords;
  vector<ll> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    coords.add(p[i]);
  }

  vector<tuple<char,int,int>> queries;
  for (int i = 0; i < q; ++i) {
    char op; int a, b;
    cin >> op >> a >> b;

    queries.emplace_back(op,a,b);
    if (op == '?') coords.add(a);
    coords.add(b);
  }

  coords.build();

  FenwickTree bit(coords.size()+1);
  for (int i = 1; i <= n; ++i) bit.add(coords.get(p[i]), 1);

  for (int i = 0; i < q; ++i) {
    auto [op, a, b] = queries[i];

    if (op == '!') {
      bit.add(coords.get(p[a]), -1);
      bit.add(coords.get(b), 1);
      p[a] = b;
    }
    else
      cout << bit.sum(coords.get(a), coords.get(b)) << '\n';
  }

  return 0;
}