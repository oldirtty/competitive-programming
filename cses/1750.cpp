/**
 * Contest : CSES Problem Set
 * Problem : 1750 - Planets Queries I
 * Link    : https://cses.fi/problemset/task/1750
 * Time    : O((N + Q) logK)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  const int LOG = 31; // 2^31
  int n, q;
  cin >> n >> q;

  vector<vector<int>> t(LOG, vector<int>(n+1, -1));
  for (int i = 1; i <= n; ++i) cin >> t[0][i];

  // Binary lifting O(log(10^9) * N)
  for (int i = 1; i < LOG; ++i)
    for (int x = 1; x <= n; ++x)
      t[i][x] = t[i-1][t[i-1][x]]; //

  while (q--) {
    ll x, k;
    cin >> x >> k;

    for (int i = 0; i < LOG; ++i)
      if (k & (1<<i)) x = t[i][x];

    cout << x << '\n';
  }

  return 0;
}