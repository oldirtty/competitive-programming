/**
 * Contest : CSES Problem Set
 * Problem : 1652 - Forest Queries
 * Link    : https://cses.fi/problemset/task/1652
 * Time    : O(N^2)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, q;
  cin >> n >> q;

  vector<vector<int>> pre(n+1, vector<int> (n+1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char ch; cin >> ch;

      pre[i][j] = pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1] + (ch=='*');
    }
  }

  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << pre[x2][y2] - pre[x2][y1-1] - pre[x1-1][y2] + pre[x1-1][y1-1] << '\n';
  }

  return 0;
}