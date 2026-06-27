/**
 * Contest : CSES Problem Set
 * Problem : 1696 - School Dance
 * Link    : https://cses.fi/problemset/task/1696
 * Time    : O(???)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

ll n, m, k, sz, src = 0, sink;
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
  vector<ll> pre(sz+1);
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

int main() {
  fastio

  cin >> n >> m >> k;
  sz = n + m;
  sink = ++sz;

  adj.assign(sz+1, {});
  cap.assign(sz+1, vector<ll> (sz+1));

  auto addEdge = [&](int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    cap[u][v] = 1;
  };

  for (int i = 1; i <= n; i++)
    addEdge(src, i);
  for (int i = 1; i <= m; i++)
    addEdge(n+i, sink);

  while (k--) {
    ll a, b;
    cin >> a >> b;
    addEdge(a, b+n);
  }
  auto mf = maxflow(src, sink);

  set<pair<int,int>> ans;
  for (int u = 1; u <= n; u++)
    for (auto v : adj[u])
      if (v > n && v <= n+m && cap[u][v] <= 0)
        ans.emplace(u, v - n);

  cout << mf << '\n';
  for (auto &[a,b] : ans)
    cout << a << ' ' <<  b << '\n';

  return 0;
}