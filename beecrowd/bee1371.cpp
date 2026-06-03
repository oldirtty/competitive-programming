/**
 * Contest : Beecrowd
 * Problem : Fechem as Portas!
 * Link    : https://judge.beecrowd.com/pt/problems/view/1371
 * Time    : O(???)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  const int N = 25000000+1;
  vector<int> crivo(N, 1);
  for (int i = 2; i < N; ++i) {
    if (crivo[i] == 1) {
      for (int j = i; j < N; j += i) {
        crivo[j] += ;
      }
    }
  }

  int n;
  while (cin >> n and n) {
    cout << "1 ";

    for (int x = 2; x <= n; ++x) {

    }
    cout << '\n';
  }

  return 0;
}
