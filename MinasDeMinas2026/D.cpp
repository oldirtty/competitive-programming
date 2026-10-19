/**
 * Contest : Minas de Minas 2026
 * Problem : D. Dardos
 * Link    : https://codeforces.com/group/YgJmumGtHD/contest/725067/problem/D
 * Time    : O(J*logN)
 */

#include <bits/stdc++.h>
using namespace std;

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define endl '\n'
#define int long long

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

const int N = 1e5+1;
struct Circulo {
    int r, x, y, id;
};
Circulo c[N];
int n, j;

bool valid(int x, int y, int m) {
    int dx = x - c[m].x, dy = y - c[m].y;
    return dx * dx + dy * dy <= c[m].r * c[m].r;
}

int bs(int x, int y) {
    int l = 0, r = n - 1, ans = 0;

    while (l <= r) {
        int m = l + (r - l) / 2;

        if (valid(x, y, m)) {
            ans = c[m].id;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return ans;
}

void solve() {
    cin >> n >> j;
    for (int i = 0; i < n; ++i) {
        int x, y, r;
        cin >> x >> y >> r;

        c[i] = {r, x, y, i + 1};
    }

    while (j--) {
        int x, y;
        cin >> x >> y;
        cout << bs(x, y) << endl;
    }
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
