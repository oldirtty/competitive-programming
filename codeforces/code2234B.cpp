/**
 * Contest : Codeforces Round 1102 (Div. 2)
 * Problem : B - Palindrome, Twelve and Two Terms
 * Link    : https://codeforces.com/contest/2234/problem/B
 * Time    : O(T * logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

bool isPalindrome(ll a) {
  string num = to_string(a);
  string rev = num;
  reverse(rev.begin(), rev.end());

  return num == rev;
}

void solve() {
  ll n; cin >> n;
  ll b = (n/12) * 12;
  while (b >= 0) {
    ll a = n-b;

    if (isPalindrome(a)) {
      cout << a << ' ' << b << '\n';
      return;
    }

    b -= 12;
  }

  cout << "-1\n";
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}