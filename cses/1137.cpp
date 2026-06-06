/**
 * Contest : CSES Problem Set
 * Problem : 1137 - Subtree Queries
 * Link    : https://cses.fi/problemset/task/1137
 * Time    : O(N * logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<int>> tree;
vector<int> subsize, order;

struct FenwickTree {
  vector<ll> v;
  int n;

  FenwickTree(int n) : n(n), v(n+1, 0) {}

  ll sum(int r) {
    int ret = 0;
    for (; r > 0; r -= r & (-r)) ret += v[r];
    return ret;
  }

  ll sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }

  void add(int idx, ll delta) {
    for (; idx <= n; idx += idx & (-idx)) v[idx] += delta;
  }
};

void dfs(int u, int p) {
  for (auto& v : tree[u]) {
    if (v==p) continue;
    dfs(v,u);
    subsize[u] += subsize[v]+1;
  }
  order.push_back(u);
}

int main() {
  fastio

  int n, q;
  cin >> n >> q;
  tree.assign(n+1, {});
  subsize.assign(n+1,0);

  vector<ll> v(n+1);
  for (int i = 1; i <= n; ++i) cin >> v[i];

  for (int i = 2; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  dfs(1, 1);
  reverse(order.begin(), order.end());
  vector<int> pos(n+1);
  for (int i = 1; i <= n; ++i) pos[order[i-1]] = i;

  FenwickTree bit(n+1);
  for (int i = 1; i <= n; ++i) bit.add(i, v[order[i-1]]);

  while (q--) {
    int op, s;
    cin >> op >> s;

    auto s_pos = pos[s];
    if (op == 1) {
      ll x; cin >> x;
      bit.add(s_pos, x - v[s]);
      v[s] = x;
    }
    else
      cout << bit.sum(s_pos, s_pos+subsize[s]) << '\n';
  }

  return 0;
}