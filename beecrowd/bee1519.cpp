/**
 * Contest : Beecrowd
 * Problem : 1519 - Abreviações
 * Link    : https://judge.beecrowd.com/pt/problems/view/1519
 * Time    : O(???)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

void solve(string& frase) {
  int n = 'z'-'a'+1;
  vector<map<string,int>> palavras(n);

  istringstream iss(frase);
  istringstream iss2(frase);

  string p;
  while (iss >> p) {
    if (p.size() > 2) {
      auto i = p[0]-'a';
      palavras[i][p] += 1;
    }
  }

  set<string> troca;
  for (auto& letra : palavras) {
    if (letra.empty()) continue;

    string melhor;
    int cnt = 0;
    for (auto& [p, freq] : letra) {
      auto total = freq * (p.size()-2);
      if (total > cnt) {
        cnt = total;
        melhor = p;
      }
    }
    if (cnt > 0) troca.insert(melhor);
  }

  p.clear();
  bool primeiro = true;
  while (iss2 >> p) {
    if (!primeiro) cout << ' ';
    if (troca.count(p)) cout << p[0] << '.';
    else cout << p;

    primeiro = false;
  }
  cout << endl;

  cout << troca.size() << endl;
  for (auto& p : troca)
    cout << p[0] << ". = " << p << endl;
}

int main() {
  fastio

  string frase;
  while (1) {
    getline(std::cin, frase);
    cout.flush();
    if (frase == ".") break;
    solve(frase);
  }

  return 0;
}