/**
 * Contest : Codeforces Round 797 (Div. 3)
 * Problem : 1690D. Black and White Stripe
 * Link    : https://codeforces.com/problemset/problem/1690/D
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
    int n, k;
    cin >> n >> k;

    string s; cin >> s;

    int cnt = 0;
    for (int i = 0; i < k; ++i)
        cnt += (s[i] == 'W');
    int ans = cnt;
    for (int i = k; i < n; ++i) {
        cnt -= (s[i - k] == 'W');
        cnt += (s[i] == 'W');
        ans = min(ans, cnt);
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
