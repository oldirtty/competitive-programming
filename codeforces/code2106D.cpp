/**
 * Contest : Codeforces Round 1020 (Div. 3)
 * Problem : 2106D. Flower Boy
 * Link    : https://codeforces.com/problemset/problem/2106/D
 * Time    : O(???)
 */

#include <bits/stdc++.h>
using namespace std;

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define endl '\n'
#define int long long

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

const int INF = 1e9+7;
void solve() {
    int N, M; cin >> N >> M;
    vector<int> a(N), b(M);

    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;

    vector<int> antes(M);
    int j = N - 1;
    for(int i = M - 1; i >= 0; --i) {
        while(j >= 0 && a[j] < b[i]) j--;
        antes[i] = j--;
    }

    vector<int> depois(M);
    j = 0;
    for(int i = 0; i < M; ++i) {
        while(j < N && a[j] < b[i]) j++;
        depois[i] = j++;
    }

    if (depois[M - 1] < N) {
        cout << 0 << endl;
        return;
    }

    int ans = INF;
    for(int i = 0; i < M; i++) {
        int anterior = i == 0 ? -1 : depois[i - 1];
        int proximo = i + 1 == M ? N : antes[i + 1];
        if (proximo > anterior) {
            ans = min(ans, b[i]);
        }
    }
    cout << (ans == INF ? -1 : ans) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    clock_t z = clock();

    int t = 1;
    cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}
