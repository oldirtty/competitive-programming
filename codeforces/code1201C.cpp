/**
 * Contest : Codeforces Round 577 (Div. 2)
 * Problem : 1201C. Maximum Median
 * Link    : https://codeforces.com/problemset/problem/1201/C
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

const int N = 2e5+1;
int n, k, a[N];

bool valid(int x) {
    int med = n / 2, sum = 0;
    for (int i = med; i < n; ++i) {
        if (x > a[i])
            sum += x - a[i];
        if (sum > k)
            return false;
    }
    return sum <= k;
}

int bs() {
    int l = 0, r = 1e18;

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
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
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
