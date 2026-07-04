/**
 * Contest : CSES Problem Set
 * Problem : 1630 - Tasks and Deadlines
 * Link    : https://cses.fi/problemset/task/1630
 * Time    : O(N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;

  vector<pair<ll, ll>> tasks(n);
  for (auto &[t, d] : tasks)
    cin >> t >> d;
  sort(tasks.begin(), tasks.end());

  ll time = 0, ans = 0;
  for (auto &[t, d] : tasks) {
    time += t;
    ans += d - time;
  }
  cout << ans << '\n';

  return 0;
}