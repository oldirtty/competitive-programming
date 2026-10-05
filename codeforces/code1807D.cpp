/**
 * Contest : Codeforces Round 859 (Div. 4)
 * Problem : 1807D. Odd Queries
 * Link    : https://codeforces.com/problemset/problem/1807/D
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
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1), pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        pref[i] = pref[i - 1] + v[i];
    }
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        int rm = pref[r] - pref[l - 1];
        int sum = (r - l + 1) * k + pref[n] - rm;
        cout << (sum & 1 ? "YES" : "NO") << endl;
    }
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
