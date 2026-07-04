/**
 * Contest : CSES Problem Set
 * Problem : 1621 - Distinct Numbers
 * Link    : https://cses.fi/problemset/task/1621
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, x;
  cin >> n;
  set<int> s;

  while (n--) {
    cin >> x;
    s.insert(x);
  }

  cout << (int)s.size() << '\n';

  return 0;
}