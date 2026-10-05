/**
 * Contest : Good Bye 2016
 * Problem : 750A. New Year and Hurry
 * Link    : https://codeforces.com/problemset/problem/750/A
 */

#include <bits/stdc++.h>
using namespace std;

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define endl '\n'

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

const int N = 10;
int t[N + 1];
void solve() {
    for (int i = 1; i <= N; ++i) t[i] = t[i - 1] + 5 * i;

    int n, k;
    cin >> n >> k;

    int rest = 4 * 60 - k;
    auto it = upper_bound(t, t + N, rest);
    --it;
    cout << min(n, (int)(it - t)) << endl;
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
