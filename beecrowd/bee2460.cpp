/**
 * Contest : Beecrowd
 * Problem : Fila
 * Link    : https://judge.beecrowd.com/pt/problems/view/2460
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  vector<int> v(n);
  set<int> s;

  for (auto& i : v) {
    cin >> i;
    s.insert(i);
  }

  int m; cin >> m;
  while (m--) {
    int x; cin >> x;
    s.erase(x);
  }

  bool first = true;
  for (auto& i : v) {
    if (s.count(i)) {
      if (!first) cout << ' ';
      cout << i;
      first = false;
    }
  }
  cout << '\n';

  return 0;
}