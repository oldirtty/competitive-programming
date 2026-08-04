/**
 * Contest : Codeforces Round 969 (Div. 2)
 * Problem : B - Index and Maximum Value
 * Link    : https://codeforces.com/problemset/problem/2007/B
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    maxi = max(maxi, a[i]);
  }

  for (int i = 0; i < m; i++) {
    char op;
    int l, r;
    cin >> op >> l >> r;

    if (l <= maxi && maxi <= r) {
      if (op == '+')
          maxi++;
      else  // op == '-'
          maxi--;
    }

    cout << maxi << " \n"[i==m-1];
  }
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}