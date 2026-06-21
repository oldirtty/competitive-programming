#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;

  // linha 1
  for (int i = 1; i <= n; ++i) cout << ' '; // n espacos
  for (int i = 1; i <= n+1; ++i) cout << '_';
  cout << '\n';

  // lin 2 ... meio
  for (int i = 1, j = n+1; i < n; ++i) {
    for (int k = 1; k <= n-i; ++k) cout << ' '; // n-i espacos
    cout << '/';
    for (int k = 1; k <= j; ++k) cout << ' '; // j espacos
    cout << "\\\n";
    j += 2;
  }

  // meio
  cout << '/';
  for (int i = 1; i <= n; ++i) cout << '_';
  for (int i = 1; i <= 2*n-1; ++i) cout << ' ';
  cout << "\\";
  for (int i = 0; i <= n; ++i) cout << '_';
  cout << "\n";
  int total = 1 + 1 + n + 2*n-1 + n+1;
  // cerr << total << "\n";

  for (int i = 1, j = n*n-1; i < n; ++i) {
    for (int k = 1; k <= n+i; ++k) cout << ' ';
    cout << "\\";
    for (int k = n+i+1; k < total-i; ++k) cout << ' ';
    cout << "/\n";
  }

  // ultima linha
  for (int i = 1; i <= 2*n; ++i) cout << ' '; // 2n espacos
  cout << "\\";
  for (int i = 1; i <= n+1; ++i) cout << '_';
  cout << "/\n";

  return 0;
}