/**
 * Contest : Beecrowd
 * Problem : Futebol
 * Link    : https://judge.beecrowd.com/pt/problems/view/1495
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, g;
  while (cin >> n >> g) {
    vector<int> diffs;
    int ans = 0;
    while (n--) {
      int a, b;
      cin >> a >> b;
      if (a <= b) diffs.push_back(b - a);
      else ans += 3;
    }

    sort(diffs.begin(), diffs.end());
    for (auto d : diffs) {
      if (g > d) {
        g -= (d + 1);
        ans += 3;
      }
      else if (g == d) {
        g -= d;
        ans += 1;
      }
      else break;
    }
    cout << ans << '\n';
  }

  return 0;
}