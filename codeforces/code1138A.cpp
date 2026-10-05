/**
 * Contest : Codeforces Round 545 (Div. 2)
 * Problem : 1138A. Sushi for Two
 * Link    : https://codeforces.com/problemset/problem/1138/A
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

void solve() {
    int n; cin >> n;
    vector<int> v(n + 1);

    for (int i = 0; i < n; ++i) cin >> v[i];

    int ans = 0, i = 0, cnt1 = 0, cnt2 = 0;
    while (i < n) {
        if (v[i] == 1) cnt1 = 0;
        else cnt2 = 0;

        int j = i;
        while (j < n && v[j] == v[i]) {
            j++;
        }
        if (v[i] == 1) cnt1 = j - i;
        else cnt2 = j - i;

        ans = max(ans, min(cnt1, cnt2) * 2);
        i = j;
    }
    ans = max(ans, min(cnt1, cnt2) * 2);
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
