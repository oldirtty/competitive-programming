/**
 * Contest : CSES Problem Set
 * Problem : 1620 - Factory Machines
 * Link    : https://cses.fi/problemset/task/1620
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<ll> machines;
ll n, t;

bool isValid(ll time) {
  ll cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += time / machines[i];
    if (cnt >= t)
      return true; // return earlier since there's no need to continue => prevents overflow or TLE
  }
  return cnt >= t;
}

ll bs() {
  ll l = 0, r = 1e18;

  while (l <= r) {
    ll mid = l + (r - l) / 2;

    if (isValid(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  return l;
}

int main() {
  fastio

  cin >> n >> t;
  machines.resize(n);
  for (auto& i : machines) cin >> i;
  cout << bs() << '\n';

  return 0;
}
