/**
 * Contest : Codeforces Round 649 (Div. 2)
 * Problem : 1364A. XXXXX
 * Link    : https://codeforces.com/problemset/problem/1364/A
 */

#include <bits/stdc++.h>
using namespace std;

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define endl endl
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

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    int sum = 0;
    for (auto& i : a) {
        cin >> i;
        sum += i;
    }

    if (sum % x != 0) {
        cout << n << endl;
        return;
    }

    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] % x != 0) {
            first = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] % x != 0) {
            last = i;
            break;
        }
    }

    if (first == -1)
        cout << -1 << endl;
    else
        cout << max(n - first - 1, last) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    clock_t z = clock();

    int t = 1;
    cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}
