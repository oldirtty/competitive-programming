/**
 * Contest : Beecrowd
 * Problem : Xenlonguinho
 * Link    : https://judge.beecrowd.com/pt/problems/view/2596
 * Time    : O(C)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    cout << n - (int)sqrt(n) << '\n';
  }

  return 0;
}