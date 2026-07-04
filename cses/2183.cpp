/**
 * Contest : CSES Problem Set
 * Problem : 2183 - Missing Coin Sum
 * Link    : https://cses.fi/problemset/task/2183
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n; cin >> n;
  vector<ll> v(n);

  for (auto &i : v) cin >> i;
  sort(v.begin(), v.end());

  ll ans = 1;
  for (auto &i : v) {
    if (i > ans) {
      cout << ans << '\n';
      return 0;
    }
    ans += i;
  }
  cout << ans << '\n';

  return 0;
}