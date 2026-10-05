/**
 * Contest : Codeforces Round 799 (Div. 4)
 * Problem : 1692E. Binary Deque
 * Link    : https://codeforces.com/problemset/problem/1692/E
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
    int n, s;
    cin >> n >> s;

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> pref[i];
        pref[i] += pref[i - 1];
    }

    int total = pref[n], rm = total - s;
    if (s > total || n < s) {
        cout << -1 << endl;
        return;
    }

    int ans = n;
    cerr << endl;
    for (int i = 0; i <= n; ++i) {
        if (pref[i] > rm) break;

        auto it = lower_bound(pref.begin(), pref.end(), total - (rm - pref[i]) + 1);
        auto idx = it - pref.begin();
        auto p = pref[n] - pref[idx - 1];
        int qtt = i + n - idx + 1;
        dbg(i, pref[i], idx, p);
        ans = min(ans, qtt);
    }
    cout << ans << endl;
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
