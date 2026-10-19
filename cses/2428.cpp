/**
 * Contest : CSES Problem Set
 * Problem : Distinct Values Subarrays II
 * Link    : https://cses.fi/problemset/task/2428
 */

#include <bits/stdc++.h>
using namespace std;

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define endl '\n'
#define int long long

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

    int v[n];
    for (auto& i : v) cin >> i;

    set<int> uniq;
    multiset<int> values;
    int cnt = 0;
    for (int l = 0, r = 0; l < n; ++l) {
        while (r < n && uniq.size() + !uniq.count(v[r]) <= k) {
            values.insert(v[r]);
            uniq.insert(v[r++]);
        }
        cnt += r - l;
        values.erase(values.find(v[l]));
        if (!values.count(v[l]))
            uniq.erase(v[l]);
    }
    cout << cnt << endl;
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
