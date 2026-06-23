/**
 * Contest : CSES Problem Set
 * Problem : 1139 - Distinct Colors
 * Link    : https://cses.fi/problemset/task/1139
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<int>> tree;
vector<unordered_set<int>> colors;
vector<int> c, ans;
int n;

void dfs(int u, int p) {
  colors[u].insert(c[u]);

  for (auto& v : tree[u]) {
    if (v != p) {
      dfs(v, u);

      if (colors[u].size() < colors[v].size())
        swap(colors[u], colors[v]);

      for (auto& i : colors[v]) colors[u].insert(i);
    }
  }
  ans[u] = colors[u].size();
}

int main() {
  fastio

  cin >> n;

  tree.assign(n+1, {});
  colors.assign(n+1, {});
  c.assign(n+1, 0);

  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = 2; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  ans.assign(n+1, 0);
  dfs(1,1);
  for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i==n];

  return 0;
}