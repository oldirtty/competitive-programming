/**
 * Contest : CSES Problem Set
 * Problem : 1085 - Array Division
 * Link    : https://cses.fi/problemset/task/1085
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define all(v) v.begin(), v.end()

ll n, k;
vector<ll> v;

bool valid(ll x) {
  ll cnt = 1, sum = 0;

  for (int i = 0; i < n; ++i) {
    sum += v[i];
    if (sum > x) {
      sum = v[i];
      cnt++;
    }
  }
  return cnt <= k;
}

ll bs() {
  ll l = *max_element(all(v)),
     r = accumulate(all(v), 1LL);

  while (l <= r) {
    ll mid = l + (r-l)/2;

    if (valid(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  return l;
}

int main() {
  fastio

  cin >> n >> k;
  v.resize(n);
  for (auto& i : v) cin >> i;
  cout << bs() << '\n';

  return 0;
}
