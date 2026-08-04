/*
 * Contest : CSES
 * Problem : 1621 - Distinct Numbers
 * Link    : https://cses.fi/problemset/task/1621
 */

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
    fastio

    ll n, x; cin >> n;
    set<ll> s;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    cout << (ll)s.size() << '\n';

    return 0;
}
