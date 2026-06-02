/**
 * Contest : CSES Problem Set
 * Problem : 1646 - Static Range Sum Queries
 * Link    : https://cses.fi/problemset/task/1646
 * Time    : O(N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, q;
  cin >> n >> q;
  vector<ll> pre(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> pre[i];
    pre[i] += pre[i-1];
  }

  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << pre[b] - pre[a-1] << '\n';
  }

  return 0;
}