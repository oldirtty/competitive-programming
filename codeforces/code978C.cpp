/**
 * Contest : Codeforces Round 481 (Div. 3)
 * Problem : 978C. Letters
 * Link    : https://codeforces.com/problemset/problem/978/C
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
    int n, m;
    cin >> n >> m;

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> pref[i];
        pref[i] += pref[i - 1];
    }

    while (m--) {
        int x; cin >> x;
        auto i = lower_bound(pref.begin(), pref.end(), x) - pref.begin();

        cout << i << " " << x - pref[i - 1] << endl;
    }
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
