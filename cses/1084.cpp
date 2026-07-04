/**
 * Contest : CSES Problem Set
 * Problem : 1084 - Apartments
 * Link    : https://cses.fi/problemset/task/1084
 * Time    : O(N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> a(n), b(m);
  for (auto& i : a) cin >> i;
  for (auto& i : b) cin >> i;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int cnt = 0, i = 0, j = 0;
  while (i < n && j < m) {
    if (b[j] < a[i] - k)
      j++;
    else if (b[j] > a[i] + k)
      i++;
    else
      cnt++, i++, j++;
  }

  cout << cnt << '\n';

  return 0;
}