/*
 * Contest : Beecrowd
 * Problem : 3351 - Clickbait
 * Link    : https://judge.beecrowd.com/pt/problems/view/3351
 * Time    : O(N logK)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<pair<ll, ll>> v; // {primeiro momento, tempo até voltar a assistir dnv}
ll n, k;

bool valid(ll x) {
  ll cnt = 0;
  for (auto &[begin, t] : v) {
    if (begin <= x) cnt += 1 + (x - begin) / t;
    if (cnt >= k) return true;
  }
  return cnt >= k;
}

ll bs() {
  ll l = 1, r = 2e18 + 1;

  while (l <= r) {
    ll m = l + (r-l)/2;

    if (valid(m))
      r = m - 1;
    else
      l = m + 1;
  }
  return l;
}

int main() {
  fastio

  cin >> n >> k;
  v.assign(n, {});
  for (auto &[begin, t] : v)
    cin >> begin >> t;

  cout << bs() << '\n';

  return 0;
}