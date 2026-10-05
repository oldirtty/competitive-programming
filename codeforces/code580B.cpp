/**
 * Contest : Codeforces Round 321 (Div. 2)
 * Problem : 580B. Kefa and Company
 * Link    : https://codeforces.com/problemset/problem/580/B
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

void solve() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> f(n);
    for (auto& [a, b] : f)
        cin >> a >> b;

    sort(f.begin(), f.end());
    int ans = 0, l = 0, r = 0, sum = 0;
    while (l < n) {
        while (r < n && f[r].first - f[l].first < d) {
            sum += f[r++].second;
            ans = max(ans, sum);
        }
        sum -= f[l++].second;
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
