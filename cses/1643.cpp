/**
 * Contest : CSES Problem Set
 * Problem : 1643 - Maximum Subarray Sum
 * Link    : https://cses.fi/problemset/task/1643
 * Time    : O(???)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;

  vector<ll> v(n), dp(n, 0);
  for (auto& i : v) cin >> i;

  ll ans;
  ans = dp[0] = v[0];
  for (int i = 1; i < n; ++i) {
    dp[i] = max(dp[i - 1] + v[i], v[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';

  return 0;
}