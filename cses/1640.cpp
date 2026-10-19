/**
 * Contest : CSES Problem Set
 * Problem : Sum of Two Values
 * Link    : https://cses.fi/problemset/task/1640
 */

#include <bits/stdc++.h>
using namespace std;

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define endl '\n'
#define int long long
#define F first
#define S second

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
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());

    int l = 0, r = n - 1;
    while (l < r) {
        int sum = v[l].F + v[r].F;
        if (sum == x) {
            cout << v[l].S << ' ' << v[r].S << endl;
            return;
        }
        else if (sum > x) {
            r--;
        }
        else if (sum < x) {
            l++;
        }
    }
    cout << "IMPOSSIBLE" << endl;
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
