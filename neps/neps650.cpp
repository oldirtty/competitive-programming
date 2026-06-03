/**
 * Contest : Neps Academy
 * Problem : Saldo de Gols
 * Link    : https://neps.academy/br/exercise/650
 * Time    : O(N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int t = 0;
void solve(int n) {
  if (!n) return;

  cout << "Teste " << ++t << '\n';

  ll bestSaldo = 0, saldoSum = 0;
  int bestI = 0, bestJ = 0;  // 0 = nenhum
  int curBegin = 1;

  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    saldoSum += a - b;

    if (saldoSum < 0) {
      saldoSum = 0;
      curBegin = i + 1;
      continue;
    }
    if (!saldoSum) continue;

    int curLen = i - curBegin + 1;
    int bestLen = bestJ - bestI + 1;
    if (saldoSum > bestSaldo || (saldoSum == bestSaldo && curLen > bestLen)) {
      bestSaldo = saldoSum;
      bestI = curBegin;
      bestJ = i;
    }
  }

  if (bestI == 0)
    cout << "nenhum\n";
  else
    cout << bestI << ' ' << bestJ << '\n';

  cout << '\n';
}


int main() {
  fastio

  int n;
  while (cin >> n, n) solve(n);

  return 0;
}