/**
 * Contest : Codeforces Round 223 (Div. 2)
 * Problem : 381A. Sereja and Dima
 * Link    : https://codeforces.com/problemset/problem/381/A
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
    int v[n];
    for (auto& i : v) cin >> i;
    int l = 0, r =  n - 1, a = 0, b = 0;
    bool turn = true;
    while (l <= r) {
        if (v[l] > v[r]) {
            if (turn) a += v[l];
            else b += v[l];
            l++;
        }
        else {
            if (turn) a += v[r];
            else b += v[r];
            r--;
        }
        turn = !turn;
    }
    cout << a << ' ' << b << endl;
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
