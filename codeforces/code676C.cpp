/*
 * Contest : Codeforces
 * Problem : 676C - Vasya and String
 * Link    : https://codeforces.com/problemset/problem/676/C
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

int n, k;
string s;

int tp(char c) {
    int cnt = 0, ans = 0;
    for (int l = 0, r = 0; l < n;) {
        while (r < n && cnt + (s[r] == c) <= k) {
            cnt += s[r++] == c;
            ans = max(ans, r - l);
        }
        cnt -= s[l++] == c;
    }
    return ans;
}

void solve() {
    cin >> n >> k;
    cin >> s;

    int v[n];
    for (auto& i : v) cin >> i;

    set<int> s;
    int cnt = 0;
    cout << max(tp('a'), tp('b')) << endl;
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
