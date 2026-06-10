/*
 * Contest : Beecrowd
 * Problem : 1391 - Quase menor caminho
 * Link    : https://judge.beecrowd.com/pt/problems/view/1391
 * Time    : O((N + M) logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const int INF = 1e9;
vector<vector<pair<int,int>>> graph, rev;
set<pair<int,int>> used;
vector<int> dist;
int n, m, s, d;

int dijkstra(int s) {
  dist.assign(n, INF);
  priority_queue<pair<int, int>> pq;

  dist[s] = 0;
  pq.push({0, s});

  while (!pq.empty()) {
    auto [du, u] = pq.top();
    pq.pop();

    if (-du > dist[u]) continue;

    for (auto& [v,w] : graph[u]) {
      if (used.count({u,v})) continue;

      if (dist[u]+w < dist[v]) {
        dist[v] = dist[u]+w;
        pq.emplace(-dist[v], v);
      }
    }
  }
  return dist[d];
}

void bfs(int src) {
  queue<int> q;
  q.push(src);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto& [v,w] : rev[u]) {
      if (dist[v]+w == dist[u]) {
        q.push(v);
        used.emplace(v, u);
      }
    }
  }
}

int main() {
  fastio

  while (cin >> n >> m, n) {
    graph.assign(n, {});
    rev.assign(n, {});

    cin >> s >> d;

    int u, v, p;
    while (m--) {
      cin >> u >> v >> p;
      graph[u].emplace_back(v,p);
      rev[v].emplace_back(u,p);
    }
    int sp = dijkstra(s);
    bfs(d);
    sp = dijkstra(s);

    cout << (sp!=INF? sp : -1) << '\n';
    used.clear();
  }

  return 0;
}