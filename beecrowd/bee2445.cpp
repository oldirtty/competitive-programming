/**
 * Contest : Beecrowd
 * Problem : 2445 - Polígono
 * Link    : https://judge.beecrowd.com/pt/problems/view/2445
 * Time    : O(N * logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  vector<ll> v(n);

  for (auto& i : v) cin >> i;
  sort(v.begin(), v.end());

  ll sum = 0, maxi = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (v[i] < sum)
      maxi = i+1;
    sum += v[i];
  }

  cout << (maxi>2? maxi : 0) << '\n';

  return 0;
}