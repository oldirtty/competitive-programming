/**
 * Contest : Beecrowd
 * Problem : Borboletas
 * Link    : https://judge.beecrowd.com/pt/problems/view/1901
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  int mat[n+1][n+1];

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> mat[i][j];

  set<int> s;
  for (int i = 0; i < 2*n; ++i) {
    int x, y;
    cin >> x >> y;
    s.insert(mat[x][y]);
  }
  cout << (int)s.size() << '\n';

  return 0;
}