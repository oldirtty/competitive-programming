/**
 * Contest : Codeforces Round 271 (Div. 2)
 * Problem : 474B. Worms
 * Link    : https://codeforces.com/problemset/problem/474/B
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
    vector<int> worms(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> worms[i];
        worms[i] += worms[i - 1];
    }

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        auto i = lower_bound(worms.begin(), worms.end(), x) - worms.begin();
        cout << i << endl;
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
