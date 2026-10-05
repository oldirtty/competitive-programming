/**
 * Contest : Codeforces Round 393 (Div. 2) (8VC Venture Cup 2017 - Final Round Div. 2 Edition)
 * Problem : 760B. Frodo and pillows
 * Link    : https://codeforces.com/problemset/problem/760/B
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

int n, m, k;

bool valid(int x) {
    int soma = x, esq = k - 1, dir = n - k;
    --x;

    if (dir) {
        if (dir > x)
            soma += (x * (x + 1)) / 2 + (dir - x);
        else {
            int ult = x - dir + 1;
            soma += (dir * (x + ult)) / 2;
        }
    }
    if (esq) {
        if (esq > x)
            soma += (x * (x + 1)) / 2 + (esq - x);
        else {
            int ult = x - esq + 1;
            soma += (esq * (x + ult)) / 2;
        }
    }
    return soma <= m;
}

int bs() {
    int l = 1, r = m;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (valid(mid)) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return r;
}

void solve() {
    cin >> n >> m >> k;
    cout << bs() << endl;
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
