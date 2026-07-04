/**
 * Contest : CSES Problem Set
 * Problem : 1673 - High Score
 * Link    : https://cses.fi/problemset/task/1673
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const ll INF = 1e18;
struct Edge {
  ll a, b, c;
};
vector<Edge> edges;
vector<vector<ll>> adj;
vector<ll> d, cycle, visited;
int n, m;

ll bellman_ford(int src) {
  d.assign(n+1, -INF);
  d[src] = 0;

  for (int i = 0; i < n; i++)
    for (auto &e : edges) {
      if (d[e.a] != -INF && d[e.a] + e.c > d[e.b]) {
        d[e.b] = d[e.a] + e.c;

        if (i == n-1)
          cycle.push_back(e.b);
      }
    }

  return d[n];
}

bool reachesN(int i) {
  visited[i] = true;
  if (i == n) return true;

  for (auto& v : adj[i]) {
    if (!visited[v]) {
      bool flag = reachesN(v);
      if (flag) return flag;
    }
  }

  return false;
}

int main() {
  fastio

  cin >> n >> m;
  visited.assign(n+1, false);
  adj.assign(n+1, {});

  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    edges.push_back({a,b,c}); // nega o peso
    adj[a].push_back(b);
  }

  auto ans = bellman_ford(1);
  for (auto &i : cycle) {
    if (!visited[i]) {
      if (reachesN(i)) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}