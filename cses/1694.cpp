/**
 * Contest : CSES Problem Set
 * Problem : 1694 - Download Speed
 * Link    : https://cses.fi/problemset/task/1694
 * Time    : O(N M^2)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

ll n, m;
vector<vector<ll>> cap;
vector<vector<ll>> adj;

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

int main() {
  fastio

  cin >> n >> m;
  adj.assign(n+1, {});
  cap.assign(n+1, vector<ll> (n+1));

  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;

    adj[a].push_back(b);
    adj[b].push_back(a);

    cap[a][b] += c;
  }
  cout << maxflow(1, n) << '\n';

  return 0;
}