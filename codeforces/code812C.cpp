/**
 * Contest : Codeforces Round 417 (Div. 2)
 * Problem : C - Sagheer and Nubian Market
 * Link    : https://codeforces.com/problemset/problem/812/C
 * Time    : O(N log²N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

ll n, s;
vector<ll> a;

bool valid(ll k, ll& cost) {
  vector<ll> costs(n+1);
  for (ll i = 1; i <= n; i++)
    costs[i] = a[i] + i * k;

  sort(costs.begin(), costs.end());

  ll sum = 0;
  for (ll i = 1; i <= k; i++) {
    sum += costs[i];
    if (sum > s) return false;
  }

  cost = sum;
  return true;
}

void bs() {
  int l = 0, r = n;
  int best_k = 0;
  ll ans = 0;

  while (l <= r) {
    ll mid = (l + r) / 2, cost = 0;

    if (valid(mid, cost)) {
      l = mid+1;
      ans = cost;
    }
    else
      r = mid-1;
  }
  cout << r << ' ' << ans << endl;
}

int main() {
  fastio

  cin >> n >> s;
  a.assign(n+1, 0);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  bs();

  return 0;
}