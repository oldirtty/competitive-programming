/**
 * Contest : CSES Problem Set
 * Problem : 1668 - Building Teams
 * Link    : https://cses.fi/problemset/task/1668
 * Time    : O(N + M)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);


vector<vector<int>> graph;
vector<int> team;

bool impossible = false;
void dfs(int u, int p, int t) {
  team[u] = t;
  for (auto& v : graph[u]) {
    if (v == p) continue;
    if (team[v] == team[u]) {
      impossible = true;
      return;
    }
    if (!team[v] && v != p)
      dfs(v, u, (t==1? 2 : 1));
  }
}

int main() {
  fastio

  int n, m;
  cin >> n >> m;
  graph.assign(n+1, {});
  team.assign(n+1, 0);

  while (m--) {
    int a, b;
    cin >> a >> b;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= n; ++i) {
    if (!impossible && !team[i])
      dfs(i, 0, 1);
  }

  if (impossible)
    cout << "IMPOSSIBLE\n";
  else
    for (int i = 1; i <= n; ++i)
      cout << team[i] << " \n"[i==n];

  return 0;
}