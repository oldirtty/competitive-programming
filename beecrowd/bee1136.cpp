/**
 * Contest : Beecrowd
 * Problem : 1136 - Bingo!
 * Link    : https://judge.beecrowd.com/pt/problems/view/1136
 * Time    : O(B^2 * logB)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, b;
  while (cin >> n >> b && n) {
    set<int> diff;
    vector<int> v(b);
    for (int i = 0; i < b; ++i) {
      cin >> v[i];
      for (int j = i; j >= 0; --j)
        diff.insert(abs(v[i]-v[j]));
    }
    cout << (diff.size()==n+1? 'Y' : 'N') << '\n';
  }

  return 0;
}