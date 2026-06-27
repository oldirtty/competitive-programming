/**
 * Contest : CSES Problem Set
 * Problem : 1695 - Police Chase
 * Link    : https://cses.fi/problemset/task/1695
 * Time    : O(N M^2)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

ll n, m;
vector<vector<ll>> cap, adj;

ll bfs(ll s, ll t, vector<ll>& pre) {
  fill(pre.begin(), pre.end(), -1);
  pre[s] = -2;
  queue<pair<ll, ll>> q;
  q.push({s, 1e18});

  while (!q.empty()) {
    auto [u,flow] = q.front();
    q.pop();

    for (auto& v : adj[u]) {
      if (pre[v] == -1 && cap[u][v] > 0) {
        pre[v] = u;
        ll new_flow = min(flow, cap[u][v]);
        if (v == t) return new_flow;

        q.push({v, new_flow});
      }
    }
  }

  return 0;
}

ll maxflow(ll s, ll t) {
  ll flow = 0;
  vector<ll> pre(n+1);
  ll new_flow;

  while (new_flow = bfs(s, t, pre)) {
    flow += new_flow;
    ll u = t;
    while (u != s) {
      ll p = pre[u];
      cap[p][u] -= new_flow;
      cap[u][p] += new_flow;
      u = p;
    }
  }

  return flow;
}

vector<bool> visited;
void dfs(int u) {
  visited[u] = true;
  for (auto& v : adj[u])
  if (!visited[v] && cap[u][v] > 0)
  dfs(v);
}

int main() {
  fastio

  cin >> n >> m;
  adj.assign(n+1, {});
  cap.assign(n+1, vector<ll> (n+1));
  visited.assign(n+1, false);

  while (m--) {
    ll a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);

    cap[a][b] = 1;
    cap[b][a] = 1;
  }
  maxflow(1, n);
  dfs(1);
  vector<pair<int,int>> ans;
  for (int u = 1; u <= n; u++) {
    if (visited[u])
      for (auto v : adj[u])
        if (!visited[v] && cap[u][v] <= 0)
          ans.emplace_back(u, v);
  }

  cout << (int)ans.size() << '\n';
  for (auto &[a,b] : ans)
    cout << a << ' ' <<  b << '\n';

  return 0;
}