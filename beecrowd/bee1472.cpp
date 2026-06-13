/**
 * Contest : Beecrowd
 * Problem : Triângulos
 * Link    : https://judge.beecrowd.com/pt/problems/view/1472
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n;
void solve () {
  vector<int> x(n+1);
  set<int> points, used;
  points.insert(0);

  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    x[i] += x[i-1];
    points.insert(x[i]);
  }

  int total = x.back();
  if (total % 3) {
    cout << "0\n";
    return;
  }

  int side = total/3, cnt = 0;

  for (int i = 0; i < n; ++i) {
    int p1 = x[i];
    int p2 = (p1+side) % total;
    int p3 = (p2+side) % total;
    int p4 = (p3+side) % total; // p4 deve ser igual p1

    if (!points.count(p2) || !points.count(p3)) continue;
    if (used.count(p1) || used.count(p2) || used.count(p3)) continue;

    // cerr << p1 << ' ' << p2 << ' ' << p3 << ' ' << p4 << '\n';
    used.insert(p1);
    cnt++;
  }
  cout << cnt << '\n';
}

int main() {
  fastio

  while (cin >> n) solve();

  return 0;
}
