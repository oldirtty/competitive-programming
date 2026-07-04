/**
 * Contest : CSES Problem Set
 * Problem : 1645 - Nearest Smaller Values
 * Link    : https://cses.fi/problemset/task/1645
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  vector<ll> v(n + 1), smallest(n + 1);
  for (int i = 1; i <= n; ++i) cin >> v[i];

  for (int i = 2; i <= n; ++i) {
    int left = i - 1;
    while (v[left] >= v[i])
      left = smallest[left];

    smallest[i] = left;
  }

  for (int i = 1; i <= n; ++i) cout << smallest[i] << " \n"[i == n];

  return 0;
}
