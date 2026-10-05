/*
 * Contest : CSES
 * Problem : 1620 - Factory Machines
 * Link    : https://cses.fi/problemset/task/1620
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

ll n, t;
vector<ll> v;

ll f(ll x) {
    ll ret = 0;
    for (auto &i : v) {
        ret += x / i;
        if (ret >= t) return ret;
    }
    return ret;
}

ll bs() {
    ll l = 0, r = 1e18, mid, ans = 0;

    while (l <= r) {
        mid = (l + r) / 2;

        if (f(mid) >= t) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return ans;
}

int main() {
    fastio

    cin >> n >> t;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    cout << bs() << '\n';
    cerr << f(bs()) << '\n';

    return 0;
}
