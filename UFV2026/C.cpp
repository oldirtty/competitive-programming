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

map<string, pair<int, int>> mp;
void solve() {
    int n; cin >> n;
    int idx = 0;
    while (n--) {
        int x;
        string s;
        cin >> x >> s;

        if (!mp.count(s)) {
            mp[s] = {x, idx};
            idx++;
        }
        else {
            mp[s].first += x;
        }
    }

    vector<pair<int, string>> v(idx);
    for (auto& [s, x] : mp) {
        v[x.second] = {x.first, s};
    }

    for (auto &[x, s] : v)
        cout << x << ' ' << s << endl;
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
