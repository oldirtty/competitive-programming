/*
 * Contest : UVA
 * Problem : 10440 - Ferry Loading II
 * Link    : https://vjudge.net/problem/UVA-10440
 * Time    : O(M)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  int n, t, m;
  cin >> n >> t >> m;
  vector<int> a(m);
  for (auto& i : a) cin >> i;

  int k = m%n, time = 0;

  if (k) time = a[k-1] + 2*t;

  while (k < m) {
    k += n;
    time = max(time, a[k-1]) + 2*t;
  }
  cout << time - t << ' ' << ceil(1.*m/n) << '\n';
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}