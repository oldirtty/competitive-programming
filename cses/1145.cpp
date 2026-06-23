/**
 * Contest : CSES Problem Set
 * Problem : 1145 - Increasing Subsequence
 * Link    : https://cses.fi/problemset/task/1145
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
  for (auto& i : v) cin >> i;

  vector<int> lis = {v[0]};
  for (int i = 1; i < n; ++i) {
    if (v[i] > lis.back())
      lis.push_back(v[i]);
    else {
      auto low = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
      lis[low] = v[i];
    }
  }
  cout << lis.size() << '\n';

  return 0;
}