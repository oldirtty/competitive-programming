/**
 * Contest : Codeforces Round 211 (Div. 2)
 * Problem : 363B. Fence
 * Link    : https://codeforces.com/problemset/problem/363/B
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
    int n, k;
    cin >> n >> k;

    int a[n];
    for (auto& i : a) cin >> i;

    int sum = 0, bestSum = 1e9, ans = -1;
    for (int i = 0; i < n; ++i) {
        if (i - k >= 0)
            sum -= a[i - k];
        sum += a[i];
        if (i >= k - 1 && sum < bestSum) {
            dbg(sum, i, i - k + 1);
            bestSum = sum;
            ans = i - k + 1;
        }
    }
    cout << ans + 1 << endl;
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
