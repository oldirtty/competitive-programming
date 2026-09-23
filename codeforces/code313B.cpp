/**
 * Contest : Codeforces Round 186 (Div. 2)
 * Problem : B. Ilya and Queries
 * Link    : https://codeforces.com/problemset/problem/313/B
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
    string s;
    cin >> s;

    int n = (int)s.size();
    vector<int> pref(n+1);

    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i-1];
        if (s[i-1] == s[i])
            pref[i]++;
    }

    cerr << s << endl;
    for (int i = 0 ; i <= n; ++i) cerr << pref[i] << " ";
    cerr << endl;

    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        int ans = pref[r-1] - pref[l-1];
        cout << ans << endl;
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
