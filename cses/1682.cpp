/**
 * Contest : CSES Problem Set
 * Problem : 1682 - Flight Routes Check
 * Link    : https://cses.fi/problemset/task/1682
 * Time    : O(N + M)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const int N = 1e5+1;
vector<vector<int>> adj, revAdj;
vector<int> order;
bitset<N> visited;
int n, m;

void topo(int u) {
    visited[u] = true;
    for(auto& v : adj[u])
        if (!visited[v]) topo(v);
    order.push_back(u);
}

void dfs(int u) {
    visited[u] = true;
    for(auto& v : revAdj[u])
        if (!visited[v]) dfs(v);
}

int main() {
    fastio

    cin >> n >> m;
    adj.assign(n + 1, {});
    revAdj.assign(n + 1, {});
    while (m--) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        revAdj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
        if (!visited[i]) topo(i);

    reverse(order.begin(), order.end());

    visited.reset();
    vector<int> comp;
    for (auto& u : order) {
        if (!visited[u]) {
            dfs(u);
            comp.push_back(u);
        }
    }

    if (comp.size() <= 1)
        cout << "YES\n";
    else {
        cout << "NO\n";
        cout << comp.back() << ' ' << comp.front() << '\n';
    }

    return 0;
}
