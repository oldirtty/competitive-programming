#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  int t = 300;

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    t += x;

    if (t > 420 && t < 600) {
      t += 180;
    }
    if (t > 1020 && t < 1200) {
      t += 180;
    }
  }

  cout << t - 300 << "\n";

  return 0;
}