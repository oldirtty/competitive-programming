/**
 * Contest : Minas de Minas 2026
 * Problem : G. Operação Sanrio
 * Link    : https://codeforces.com/group/YgJmumGtHD/contest/725067/problem/G
 * Time    : O(N*M)
 */

#include <bits/stdc++.h>
using namespace std;

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define endl '\n'
using pii = pair<int, int>;

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

const int N = 6;
int n, m;
vector<string> g;
vector<pii> pos(N); // posição de cada um
int dist[N][N];     // dist[i][j] = distância entre 2 amigos (pos[i] e pos[j])
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

vector<vector<int>> bfs(int sr, int sc) {
    vector<vector<int>> d(n, vector<int>(m, -1));
    queue<pii> q;
    d[sr][sc] = 0;
    q.push({sr, sc});
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (g[x][y] == '#' || d[x][y] != -1) continue;
            d[x][y] = d[i][j] + 1;
            q.push({x, y});
        }
    }
    return d;
}

void solve() {
    cin >> n >> m;
    g.resize(n);
    for (auto& s : g) cin >> s;

    string chars = "HKCMPQ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            size_t k = chars.find(g[i][j]);
            if (k != string::npos) pos[k] = {i, j};
        }
    }

    for (int s = 0; s < N; s++) {
        auto d = bfs(pos[s].first, pos[s].second);
        for (int j = 0; j < N; j++)
            dist[s][j] = d[pos[j].first][pos[j].second];
    }

    // amigos alcançáveis a partir de H, posicoes 1..5
    vector<int> reach;
    for (int i = 1; i < N; i++)
        if (dist[0][i] != -1)
            reach.push_back(i);

    if (reach.empty()) {
        cout << "0 0" << endl;
        return;
    }

    // testa todas as ordens de visita
    sort(reach.begin(), reach.end());
    int best = INT_MAX;
    do {
        int cost = dist[0][reach[0]];
        for (size_t i = 0; i + 1 < reach.size(); i++)
            cost += dist[reach[i]][reach[i + 1]];
        best = min(best, cost);
    } while (next_permutation(reach.begin(), reach.end()));

    cout << reach.size() << " " << best << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    clock_t z = clock();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}
