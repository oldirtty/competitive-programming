/**
 * Contest : Beecrowd
 * Problem : Poker do Rei
 * Link    : https://judge.beecrowd.com/pt/problems/view/1337
 * Time    : O(1)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve(int a, int b, int c) {
  map<int,int> cnt;
  cnt[a]++; cnt[b]++, cnt[c]++;

  multiset<int> ans;

  // set: 3 iguais
  if (cnt.size() == 1) {
    if (a==13) {
      cout << "*\n";
      return;
    }
    else
      for (int i = 1; i <= 3; ++i) ans.insert(a+1);
  }
  // par
  else if (cnt.size() == 2) {
    int par = -1, unica = -1;
    for (auto& [c, qtt] : cnt) {
      if (qtt == 2) par = c;
      else unica = c;
    }

    if (unica == 13) {
      ans.insert(1);
      ans.insert(par+1);
      ans.insert(par+1);
    }
    else if (par == 13 && unica == 12)
      for (int i = 1; i <= 3; ++i) ans.insert(1);
    else if (par <= 13) {
      ans.insert(par);
      ans.insert(par);
      if (unica+1 == par)
        ans.insert(unica+2);
      else
        ans.insert(unica+1);
    }
  }
  else {
    ans.insert(1);
    ans.insert(1);
    ans.insert(2);
  }

  bool first = true;
  for (auto& i : ans) {
    if (!first) cout << ' ';
    cout << i;
    first = false;
  }
  cout << '\n';
}

int main() {
  fastio

  int a, b, c;
  while (cin >> a >> b >> c && a)
    solve(a,b,c);

  return 0;
}