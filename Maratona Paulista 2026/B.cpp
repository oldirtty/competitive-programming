#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, c, k;
  cin >> n >> c >> k;
  vector<ll> d(n), dp(n);

  for (auto& i : d) cin >> i;

  dp[0] = k+c;
  for (int i = 1; i < n; ++i) {
    dp[i] = dp[i-1] + min((d[i] - d[i-1])*c, k+c);
  }
  cout << dp[n-1] << "\n";

  return 0;
}