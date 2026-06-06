/**
 * Contest : CSES Problem Set
 * Problem : 1745 - Money Sums
 * Link    : https://cses.fi/problemset/task/1745
 * Time    : O(N * SUM)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  const int N = 100*1000+1;
  int n; cin >> n;

  vector<int> coins(n);
  for (auto& i : coins) cin >> i;

  bitset<N> dp;
  set<int> ans;
  dp[0] = 1;
  for (auto& c : coins) {
    for (int x = N-1; x >= c; --x) {
      dp[x] = dp[x-c] || dp[x];

      if (dp[x]) ans.insert(x);
    }
  }

  cout << (int)ans.size() << '\n';
  for (auto& i : ans)
    cout << i << " \n"[i==*ans.rbegin()];

  return 0;
}