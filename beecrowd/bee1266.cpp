/**
 * Contest : Beecrowd
 * Problem : Tornado!
 * Link    : https://judge.beecrowd.com/pt/problems/view/1266
 * Time    : O(N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const int N = 5e3+1;
int n;
void solve() {
  bitset<N> posts;

  int start = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (x && !start) start = i;
    posts[i] = x;
  }

  int cnt = 0, q = n, i = start;
  while (q--) {
    int pre = (i-1 + n) % n;

    if (!posts[pre] && !posts[i]) {
      posts[i] = 1;
      cnt++;
    }

    i = (i+1) % n;
  }

  cout << cnt << '\n';
}

int main() {
  fastio

  while (cin >> n && n) solve();

  return 0;
}