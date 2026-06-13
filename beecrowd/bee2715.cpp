/**
 * Contest : Beecrowd
 * Problem : Dividindo os Trabalhos I
 * Link    : https://judge.beecrowd.com/pt/problems/view/2715
 * Time    : O(N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n;
  while (cin >> n) {
    ll total = 0;
    vector<ll> v(n);
    for (auto& i : v) {
      cin >> i;
      total += i;
    }

    ll ans = total, sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += v[i];
      ans = min(ans, abs(total - 2*sum));
    }
    cout << ans << '\n';
  }

  return 0;
}