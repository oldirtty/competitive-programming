/**
 * Contest : Codeforces Round 218 (Div. 2)
 * Problem : 371C. Hamburgers
 * Link    : https://codeforces.com/problemset/problem/371/C
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

const int N = 3;
string s; // B S C
int tem[N], p[N], ing[N];
int r;

bool valid(int x) {
    int custo = 0;
    for (int i = 0; i < N; ++i) {
        int needed = ing[i] * x - tem[i];
        if (needed <= 0) needed = 0;
        custo += needed * p[i];
    }

    return custo <= r;
}

int bs() {
    int l = 0, r = 1e13;

    while (l <= r) {
        int m = l + (r - l) / 2;

        if (valid(m)) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return max(0LL, r);
}

void solve() {
    cin >> s;

    for (auto& c : s) {
        if (c == 'B') ing[0]++;
        if (c == 'S') ing[1]++;
        if (c == 'C') ing[2]++;
    }
    for (int i = 0; i < N; ++i) cin >> tem[i];
    for (int i = 0; i < N; ++i) cin >> p[i];
    cin >> r;

    cout << bs() << endl;
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
