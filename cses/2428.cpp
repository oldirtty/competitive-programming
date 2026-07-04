/**
 * Contest : CSES Problem Set
 * Problem : 2428 - Distinct Values Subarrays II
 * Link    : https://cses.fi/problemset/task/2428
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main(){
  fastio

  ll n, k;
  cin >> n >> k;

  vector<ll> v(n);
  for (auto &i : v) cin >> i;

  map<ll, ll> freq;
  ll ans = 0;
  for (int l = 0, r = 0; l < n; ++l) {
    while(r < n && freq.size()+!(freq.count(v[r])) <= k) {
      ans += r - l + 1;
      freq[v[r++]] += 1;
    }

    freq[v[l]]--;
    if(!freq[v[l]]) freq.erase(v[l]);
  }
  cout << ans << '\n';

  return 0;
}