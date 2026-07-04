/**
 * Contest : CSES Problem Set
 * Problem : 3420 - Distinct Values Subarrays
 * Link    : https://cses.fi/problemset/task/3420
 * Time    : O(N)
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
  set<ll> s;

  ll cnt = 0;
  for (int l = 0, r = 0; l < n; ++l) {
    while (r < n) {
      if (s.count(v[r])) break;
      s.insert(v[r++]);
    }

    cnt += r - l;
    s.erase(v[l]);
  }
  cout << cnt << '\n';

  return 0;
}