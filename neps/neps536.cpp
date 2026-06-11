/*
 * Contest : OBI 2011 - Fase 2
 * Problem : Balé
 * Link    : https://neps.academy/br/exercise/536
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

ll ans = 0;
ll merge(vector<ll> &v, ll l, ll mid, ll r) {
  ll n = mid - l + 1, m = r - mid;
  ll left[n], right[m], cnt = 0;

  for (ll i = 0; i < n; ++i) left[i] = v[l + i];
  for (ll i = 0; i < m; ++i) right[i] = v[mid + 1 + i];

  ll i = 0, j = 0, k = l;
  while (i < n && j < m) {
    if (left[i] < right[j]) {
      v[k++] = left[i++];
    }
    else {
      cnt += n - i;
      v[k++] = right[j++];
    }
  }
  while (i < n) v[k++] = left[i++];
  while (j < m) v[k++] = right[j++];

  return cnt;
}

ll mergesort(vector<ll> &v, ll l, ll r) {
  if (l < r) {
    ll m = l + (r - l) / 2;

    ans += mergesort(v, l, m);
    ans += mergesort(v, m + 1, r);
    return merge(v, l, m, r);
  } else
    return 0;
}

int main() {
  fastio

  ll n; cin >> n;
  vector<ll> v(n);

  for (auto &i : v) cin >> i;

  ans += mergesort(v, 0, n - 1);
  cout << ans << '\n';

  return 0;
}