/**
 * Contest : CSES Problem Set
 * Problem : 1090 - Ferris Wheel
 * Link    : https://cses.fi/problemset/task/1090
 * Time    : O(N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, max;
  cin >> n >> max;

  vector<int> v(n);
  for (auto& i : v) cin >> i;

  sort(v.begin(), v.end());

  int cnt = 0, i = 0, j = n - 1;
  while (i <= j) {
    if (v[i] + v[j] <= max) i++;
    cnt++, j--;
  }
  cout << cnt << '\n';

  return 0;
}