/**
 * Contest : CSES Problem Set
 * Problem : Maximum Subarray Sum II
 * Link    : https://cses.fi/problemset/task/1644
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
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> pref[i];
        pref[i] += pref[i - 1];
    }
    int ans = -1e18;
    multiset<int> left;

    for (int i = 1; i <= n; ++i) {
        if (i >= a)
            left.insert(pref[i - a]);
        if (i > b)
            left.erase(left.find(pref[i - b - 1]));
        if (!left.empty())
            ans = max(ans, pref[i] - *left.begin());
    }
    cout << ans << endl;
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
