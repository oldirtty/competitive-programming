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

vector<vector<int>> tree, up;
vector<int> depth;

int LOG, n;
void dfs_lca(int u, int p) {
  up[u][0] = p;
  for (int k = 1; k <= LOG; ++k)
    up[u][k] = up[up[u][k-1]][k-1];

  for (auto v : tree[u])
    if (v != p) {
      depth[v] = depth[u] + 1;
      dfs_lca(v, u);
    }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int diff = depth[u] - depth[v];

  for (int k = 0; k <= LOG; ++k)
    if (diff & (1 << k)) u = up[u][k];

  if (u == v) return u;

  for (int k = LOG; k >= 0; --k) {
    if (up[u][k] != up[v][k]) {
      u = up[u][k];
      v = up[v][k];
    }
  }

  return up[u][0];
}

int main() {
  fastio

  int n, q, a, b;
  cin >> n >> q;

  LOG = (int)ceil(log2(n));
  depth.assign(n+1, 0);
  up.assign(n+1, vector<int>(LOG+1));
  tree.assign(n+1, {});

  for (int i = 2; i <= n; ++i) {
    cin >> a >> b;

    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  dfs_lca(1, 1);

  while (q--) {
    cin >> a >> b;
    cout << depth[a] + depth[b] - 2*depth[lca(a, b)] << '\n';
  }

  return 0;
}