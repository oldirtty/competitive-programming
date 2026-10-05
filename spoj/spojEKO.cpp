/**
 * Contest : SPOJ
 * Problem : Eko
 * Link    : https://vjudge.net/problem/SPOJ-EKO
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

const int N = 1e6+1;
int n, m, a[N];

bool valid(int x) {
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] > x) sum += a[i] - x;
        // if (sum >= m) return true;
    }
    return sum >= m;
}

int bs() {
    int l = 0, r = *max_element(a, a + n);

    while (l <= r) {
        int mid =  l + (r - l) / 2;

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
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << bs() << endl;
}

int32_t main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    clock_t z = clock();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}
