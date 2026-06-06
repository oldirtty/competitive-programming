/**
 * Contest : CSES Problem Set
 * Problem : 1144 - Salary Queries
 * Link    : https://cses.fi/problemset/task/1144
 * Time    : O(???)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, q;
  cin >> n >> q;

  multiset<pair<ll,int>> salaries;
  vector<ll> emp(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> emp[i];
    salaries.insert({emp[i],i});
  }

  return 0;
}