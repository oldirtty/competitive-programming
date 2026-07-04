/**
 * Contest : CSES Problem Set
 * Problem : 1629 - Movie Festival
 * Link    : https://cses.fi/problemset/task/1629
 * Time    : O(N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n; cin >> n;

  vector<pair<ll,ll>> v(n);
  for (auto& [a,b] : v) cin >> b >> a;
  sort(v.begin(), v.end());

  ll curr = v[0].first, cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (v[i].second >= curr) {
      curr = v[i].first;
      cnt++;
    }
  }
  cout << cnt << '\n';

  return 0;
}