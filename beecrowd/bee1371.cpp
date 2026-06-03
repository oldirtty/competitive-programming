/**
 * Contest : Beecrowd
 * Problem : Fechem as Portas!
 * Link    : https://judge.beecrowd.com/pt/problems/view/1371
 * Time    : O(√N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n;
  while (cin >> n and n) {
    bool first = true;
    for (ll i = 1; i*i <= n; ++i) {
      if (!first) cout << ' ';
      cout << i*i;
      first = false;
    }
    cout << '\n';
  }

  return 0;
}