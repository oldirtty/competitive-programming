/**
 * Contest : Codeforces Round 881 (Div. 3)
 * Problem : 1843A. Sasha and Array Coloring
 * Link    : https://codeforces.com/problemset/problem/1843/A
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
    int n; cin >> n;
    int v[n];
    for (auto& i : v)
        cin >> i;

    sort(v, v + n);
    int l = 0, r = n - 1, ans = 0;
    while (l < r)
        ans += v[r--] - v[l++];
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
