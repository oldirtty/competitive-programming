/**
 * Contest : Codeforces Round 1102 (Div. 2)
 * Problem : A - Euclid, Sequence and Two Numbers
 * Link    : https://codeforces.com/contest/2234/problem/A
 * Time    : O(N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  int n; cin >> n;
  vector<int> v(n);
  for (auto& i : v) cin >> i;
  sort(v.rbegin(), v.rend());
  v.push_back(0);

  bool flag = true;
  for (int i = 0; i < n-2; ++i)
    if (v[i] % v[i+1] != v[i+2])
      flag = false;

  if (flag)
    cout << v[0] << ' ' << v[1] << '\n';
  else
    cout << "-1\n";
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}