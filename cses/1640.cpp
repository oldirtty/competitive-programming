/**
 * Contest : CSES Problem Set
 * Problem : 1640 - Sum of Two Values
 * Link    : https://cses.fi/problemset/task/1640
 * Time    : O(N)
 */

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, x;
  cin >> n >> x;

  pii a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i+1;
  }

  sort(a, a+n);
  int l = 0, r = n-1;
  while (l < r) {
    int sum = a[l].first + a[r].first;
    if (sum == x) {
      cout << a[l].second << ' ' << a[r].second << '\n';
      return 0;
    }
    else if (sum > x)
      r--;
    else
      l++;
  }
  cout << "IMPOSSIBLE\n";

  return 0;
}