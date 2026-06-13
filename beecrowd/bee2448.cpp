/**
 * Contest : Beecrowd
 * Problem : Carteiro
 * Link    : https://judge.beecrowd.com/pt/problems/view/2448
 * Time    : O(M logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, m;
  cin >> n >> m;

  vector<int> v(n), q(m);
  map<int,int> pos;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;

    pos[x] = i;
  }

  int curr = 0, ans = 0;
  for (auto &i : q) {
    cin >> i;
    ans += abs(curr-pos[i]);

    curr = pos[i];
  }
  cout << ans << '\n';

  return 0;
}