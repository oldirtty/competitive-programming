/**
 * Contest : Codeforces Round 1017 (Div. 4)
 * Problem : 2094D. Tung Tung Sahur
 * Link    : https://codeforces.com/problemset/problem/2094/D
 */

#include <bits/stdc++.h>
using namespace std;

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define endl '\n'

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

void solve() {
    string p, s;
    cin >> p >> s;

    int n = p.size(),
        m = s.size(),
        i = 0, j = 0;

    while (i < n && j < m) {
        if (p[i] != s[j]) {
            cout << "NO\n";
            return;
        }

        char c = p[i];
        int cntP = 0, cntS = 0;

        while (i < n && p[i] == c)
            i++, cntP++;
        while (j < m && s[j] == c)
            j++, cntS++;

        if (cntS > 2 * cntP || cntS < cntP || (i < n && j < m && p[i] != s[j])) {
            cout << "NO\n";
            return;
        }
    }
    if (i < n || j < m)
        cout << "NO\n";
    else
        cout << "YES\n";
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
