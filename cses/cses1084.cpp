/*
 * Contest : CSES
 * Problem : 1084 - Apartments
 * Link    : https://cses.fi/problemset/task/1084
 */

#include <bits/stdc++.h>
using namespace std;

#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n), b(m);

    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll cnt = 0;
    for (int i = 0, j = 0; i < n && j < m;) {
        if (b[j] < a[i] - k) {
            j++;
        }
        else if (b[j] > a[i] + k) {
            i++;
        }
        else {
            cnt++;
            i++, j++;
        }
    }

    cout << cnt << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}
