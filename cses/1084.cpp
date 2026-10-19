/**
 * Contest : CSES Problem Set
 * Problem : Apartments
 * Link    : https://cses.fi/problemset/task/1084
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
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;

    sort(a, a + n);
    sort(b, b + m);

    int cnt = 0, i = 0, j = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) {
            cnt++, i++, j++;
        }
        else if (a[i] > b[j]) {
            j++;
        }
        else if (a[i] < b[j]) {
            i++;
        }
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
