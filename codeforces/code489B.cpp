/**
 * Contest : Codeforces Round 277.5 (Div. 2)
 * Problem : 489B. BerSU Ball
 * Link    : https://codeforces.com/problemset/problem/489/B
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

const int N = 101;
int a[N], b[N];
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int m; cin >> m;
    for (int i = 0; i < m; ++i) cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= 1) {
            i++, j++, cnt++;
        }
        else if (a[i] < b[j]) i++;
        else if (b[j] < a[i]) j++;
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
