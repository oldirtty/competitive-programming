/**
 * Contest : Codeforces Round 219 (Div. 1)
 * Problem : 372A. Counting Kangaroos is Fun
 * Link    : https://codeforces.com/problemset/problem/372/A
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

const int N = 5e5+5;
int a[N];
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);
    int cnt = n, l = 0, r = n / 2;
    while (l < n / 2 && r < n) {
        if (a[l] * 2 <= a[r]) {
            cnt--;
            l++;
        }
        r++;
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
