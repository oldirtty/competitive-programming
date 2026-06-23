/**
 * Contest : CSES Problem Set
 * Problem : 1135 - Distance Queries
 * Link    : https://cses.fi/problemset/task/1135
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<int>> tree;
vector<vector<int>> up;
vector<int> depth;

int LOG, n;
void dfs_lca(int u, int p) {
  up[0][u] = p;
  for (int i = 1; i <= LOG; ++i)
    up[i][u] = up[i-1][up[i-1][u]];

  for (auto v : tree[u]) {
    if (v != p) {
      depth[v] = depth[u] + 1;
      dfs_lca(v, u);
    }
  }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int diff = depth[u] - depth[v];

  for (int i = 0; i <= LOG; ++i)
    if (diff & (1 << i)) u = up[i][u];

  if (u == v) return u;

  for (int i = LOG; i >= 0; --i) {
    if (up[i][u] != up[i][v]) {
      u = up[i][u];
      v = up[i][v];
    }
  }

  return up[0][u];
}

int main() {
  fastio

  int n, q;
  cin >> n >> q;

  LOG = (int)ceil(log2(n));
  depth.assign(n+1, 0);
  up.assign(LOG+1, vector<int>(n+1));
  tree.assign(n+1, {});

  for (int i = 2; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  dfs_lca(1, 1);

  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << depth[a] + depth[b] - 2*depth[lca(a, b)] << '\n';
  }

  return 0;
}