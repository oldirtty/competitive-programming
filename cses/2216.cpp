/**
 * Contest : CSES Problem Set
 * Problem : 2216 - Collecting Numbers
 * Link    : https://cses.fi/problemset/task/2216
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

  map<ll, ll> freq;
  for (int i = 1; i <= n; ++i) freq[i] = 0;

  ll cnt = 1;
  for (auto& i : v) {
    cin >> i;

    if (freq[i-1] == 0)
      freq[i] = cnt++;
    else
      freq[i] = freq[i-1];
  }

  cout << cnt-1 << '\n';

  return 0;
}