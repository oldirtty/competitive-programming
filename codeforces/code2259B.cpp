/**
 * Contest : Codeforces Round 1119 (Div. 3)
 * Problem : B. Minus Two
 * Link    : https://codeforces.com/contest/2259/problem/B
 * Time    : O(???)
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

    vector<int> even;
    int odd = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x & 1) odd++;
        else even.push_back(x);
    }
    int ans = odd;
    map<int, int> groups;
    for (auto &x : even) {
        int dist = 0;
        while (x > 2) {
            x = abs(x - 2);
            dist++;
        }
        groups[x * 2 + dist % 2]++;
    }
    int maxEven = 0;
    for (auto& p : groups) {
        maxEven = max(maxEven, p.second);
    }

    cout << max(odd, maxEven) << endl;
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
