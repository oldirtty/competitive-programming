/**
 * Contest : Educational Codeforces Round 132 (Rated for Div. 2)
 * Problem : 1709B. Also Try Minecraft
 * Link    : https://codeforces.com/problemset/problem/1709/B
 */

#include <bits/stdc++.h>
using namespace std;

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define endl '\n'
#define int long long

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
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), pref(n + 1), suf(n + 1);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + -min(v[i] - v[i - 1], 0LL);
    for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + -min(v[i] - v[i + 1], 0LL);

    while (m--) {
        int l, r;
        cin >> l >> r;

        if (l < r)
            cout << pref[r] - pref[l] << endl;
        else
            cout << suf[r] - suf[l] << endl;
    }
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
