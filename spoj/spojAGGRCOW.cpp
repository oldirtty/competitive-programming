/**
 * Contest : SPOJ
 * Problem : Aggressive cows
 * Link    : https://vjudge.net/problem/SPOJ-AGGRCOW
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

const int N = 1e5+1;
int n, c, x[N];

bool valid(int dist) {
    int cnt = 1, last = x[0];

    for (int i = 1; i < n; ++i) {
        if (x[i] - last >= dist) {
            last = x[i];
            cnt++;
        }
    }
    return cnt >= c;
}

int bs() {
    int l = 0,
        r = x[n - 1] - x[0];

    while (l <= r) {
        int m = l + (r - l) / 2;

        if (valid(m)) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return r;
}

void solve() {
    cin >> n >> c;
    for (int i = 0; i < n; ++i) cin >> x[i];
    sort(x, x + n);
    cout << bs() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    clock_t z = clock();

    int k = 1;
    cin >> k;
    while (k--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}
