/**
 * Contest : CSES Problem Set
 * Problem : 1688 - Company Queries II
 * Link    : https://cses.fi/problemset/task/1688
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<int>> tree, up;
vector<int> depth;

int LOG, n;
void dfs(int u, int p) {
  up[u][0] = p;
  for (int i = 1; i <= LOG; ++i)
    up[u][i] = up[up[u][i-1]][i-1];

  for (auto v : tree[u]) {
    if (v != p) {
      depth[v] = depth[u] + 1;
      dfs(v, u);
    }
  }
}

int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  int diff = depth[a] - depth[b];

  for (int i = 0; i <= LOG; ++i)
    if (diff & (1 << i))
      a = up[a][i];

  if (a == b) return a;

  for (int i = LOG; i >= 0; --i) {
    if (up[a][i] != up[b][i]) {
      a = up[a][i];
      b = up[b][i];
    }
  }

  return up[a][0];
}

int main() {
  fastio

  int n, q;
  cin >> n >> q;

  LOG = (int)ceil(log2(n));
  depth.assign(n+1, 0);
  up.assign(n+1, vector<int>(LOG+1));
  tree.assign(n+1, {});

  for (int i = 2; i <= n; ++i) {
    int p; cin >> p;
    tree[p].push_back(i);
    tree[i].push_back(p);
  }
  dfs(1, 1);

  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << lca(a, b) << '\n';
  }

  return 0;
}