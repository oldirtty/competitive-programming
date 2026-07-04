/**
 * Contest : CSES Problem Set
 * Problem : 1163 - Traffic Lights
 * Link    : https://cses.fi/problemset/task/1163
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, x;
  cin >> n >> x;

  set<int> lights;
  multiset<int> len;
  lights.insert(0);
  lights.insert(n);
  len.insert(n);

  for (int i = 0; i < x; ++i) {
    int t; cin >> t;

    auto end = lights.upper_bound(t);
    auto st = end;
    st--;

    len.insert(*end - t);
    len.erase(len.find(*end - *st));
    len.insert(t - *st);

    auto ans = len.end();
    cout << *(--ans) << ' ';

    lights.insert(t);
  }
  cout << '\n';

  return 0;
}