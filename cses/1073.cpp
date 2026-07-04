/**
 * Contest : CSES Problem Set
 * Problem : 1073 - Towers
 * Link    : https://cses.fi/problemset/task/1073
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  multiset<int> towers;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;

    auto it = towers.upper_bound(x);
    if (it == towers.end()) towers.insert(x);
    else {
      towers.erase(it);
      towers.insert(x);
    }
  }
  cout << towers.size() << '\n';

  return 0;
}