/**
 * Contest : Codeforces Round 215 (Div. 2)
 * Problem : 368B. Sereja and Suffixes
 * Link    : https://codeforces.com/problemset/problem/368/B
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
    int n, m;
    cin >> n >> m;;

    vector<int> v(n);
    for (auto& i : v) cin >> i;

    vector<pair<int, int>> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i].first;
        q[i].second = i;
    }
    sort(q.begin(), q.end());
    reverse(q.begin(), q.end());

    set<int> s;
    vector<int> ans(m);
    int j = n - 1;
    for (int i = 0; i < m; ++i) {
        auto [pos, idx] = q[i];

        while (j >= pos - 1) {
            s.insert(v[j--]);
        }

        ans[idx] = s.size();
    }
    for (auto& i : ans)
        cout << i << endl;
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
