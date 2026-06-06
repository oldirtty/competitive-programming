/**
 * Contest : CSES Problem Set
 * Problem : 2134 - Path Queries II
 * Link    : https://cses.fi/problemset/task/2134
 * Time    : O(N * logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<int>> tree, up;
vector<int> val, depth;
int n, q, LOG;

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
  int maxU = val[u], maxV = val[v];
  int diff = depth[u] - depth[v];

  for (int i = 0; i <= LOG; ++i)
    if (diff & (1 << i)) {
      u = up[i][u];
      maxU = max(maxU, val[u]);
    }

  if (u == v) return max(maxU, maxV);

  for (int i = LOG; i >= 0; --i) {
    if (up[i][u] != up[i][v]) {
      u = up[i][u];
      v = up[i][v];
      maxU = max(maxU, val[u]);
      maxV = max(maxU, val[u]);
    }
  }
  maxU = max(maxU, val[u]);
  maxV = max(maxU, val[u]);

  return max(up[0][u], max(maxU, maxV));
}

int main() {
  fastio

  cin >> n >> q;
  LOG = (int)ceil(log2(n));

  tree.assign(n+1, {});
  up.assign(LOG+1, vector<int>(n+1));
  depth.assign(n+1, 0);
  val.assign(n+1, 0);

  for (int i = 1; i <= n; ++i) cin >> val[i];

  for (int i = 2; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  dfs_lca(1, 1);

  while (q--) {
    int op; cin >> op;

    if (op == 1) {
      int s, x;
      cin >> s >> x;
      val[s] = x;
    }
    else {
      int a, b;
      cin >> a >> b;

      cout << lca(a,b) << ' ';
    }
  }
  cout << '\n';

  return 0;
}