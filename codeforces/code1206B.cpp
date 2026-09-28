/**
 * Contest : Codeforces Round 580 (Div. 2)
 * Problem : 1206B. Make Product Equal One
 * Link    : https://codeforces.com/problemset/problem/1206/B
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
    int n; cin >> n;

    int ans = 0, cntNegative = 0, cntZero = 0;
    vector<int> v(n);
    for (auto& i : v) {
        cin >> i;
        if (i < 0) cntNegative++;
        else if (i == 0) cntZero++;
        if (abs(i) != 1) ans += abs(abs(i) - 1);
    }
    if ((cntNegative & 1) && !cntZero) ans += 2;
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
