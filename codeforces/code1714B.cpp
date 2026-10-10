/**
 * Contest : Codeforces Round 811 (Div. 3)
 * Problem : 1714B. Remove Prefix
 * Link    : https://codeforces.com/problemset/problem/1714/B
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
    int a[n];
    for (auto& i : a) cin >> i;

    vector<int> last(n + 1), pos(n + 1);
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        if (pos[x])
            last[i] = pos[x];
        pos[x] = i + 1;
    }
    cout << *max_element(last.begin(), last.end()) << endl;
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
