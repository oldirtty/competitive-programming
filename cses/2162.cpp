/**
 * Contest : CSES Problem Set
 * Problem : 2162 - Josephus Problem I
 * Link    : https://cses.fi/problemset/task/2162
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  set<int> s;
  for (int i = n; i > 0; i--) s.insert(i);

  auto it = s.begin();
  while (!s.empty()) {
    it++;
    if (it == s.end()) it = s.begin();

    cout << *it << ' ';

    auto nxt = next(it);
    if (nxt == s.end()) nxt = s.begin();

    s.erase(it);
    it = nxt;
  }
  cout << '\n';

  return 0;
}