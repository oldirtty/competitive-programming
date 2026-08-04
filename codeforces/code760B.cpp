/**
 * Contest : Codeforces Round 393 (Div. 2) (8VC Venture Cup 2017 - Final Round Div. 2 Edition)
 * Problem : B - Frodo and pillows
 * Link    : https://codeforces.com/problemset/problem/760/B
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

ll n, m, k;
ll f(ll len, ll x) {
  ll first = max(1LL, x-len+1), last = x, cnt = 0;
  if (len > x)
    cnt += len-x;

  cnt += (first + last) * (last - first + 1)/2;
  return cnt;
}

bool valid(ll x) {
  ll left = k-1, right = n-k;
  return x + f(left,x-1) + f(right, x-1) <= m;
}

ll bs() {
  ll l = 1, r = m;

  while (l <= r) {
    ll mid = l + (r-l)/2;
    if (valid(mid))
      l = mid+1;
    else
      r = mid-1;
  }
  return r;
}

int main() {
  fastio

  cin >> n >> m >> k;
  cout << bs() << endl;

  return 0;
}