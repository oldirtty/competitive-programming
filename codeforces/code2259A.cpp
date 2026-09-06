/**
 * Contest : Codeforces Round 1119 (Div. 3)
 * Problem : A. Moo Language School
 * Link    : https://codeforces.com/contest/2259/problem/A
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
    int n, k;
    cin >> n >> k;

    vector<int> fields((n / k) + 1, 0);
    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
        char x; cin >> x;
        int idx = (i + k - 1) / k; // ceiling
        fields[idx] += x - '0';
        cnt += fields[idx] == k;
    }
    cout << cnt << endl;
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
