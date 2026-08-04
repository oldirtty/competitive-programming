/**
 * Contest : Codeforces Round 1101 (Div. 2)
 * Problem : A - Convergence
 * Link    : https://codeforces.com/problemset/problem/2232/A
 * Time    : O(T N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

void solve() {
  int n; cin >> n;
  vector<int> v(n);

  for (auto& i : v) cin >> i;
  sort(v.begin(), v.end());

  int median = v[n/2], cnt1 = 0, cnt2 = 0;
  for (auto& i : v) {
    cnt1 += (i<median);
    cnt2 += (i>median);
  }
  cout << max(cnt1,cnt2) << endl;
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}