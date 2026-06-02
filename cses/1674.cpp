/**
 * Contest : CSES Problem Set
 * Problem : 1674 - Subordinates
 * Link    : https://cses.fi/problemset/task/1674
 * Time    : O(N + M)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<int>> tree;
vector<int> subsize;

void dfs(int u) {
  if (tree[u].empty()) return;

  for (auto& v : tree[u]) {
    dfs(v);
    subsize[u] += subsize[v]+1;
  }
}

int main() {
  fastio

  int n; cin >> n;
  tree.assign(n+1, {});
  subsize.assign(n+1, 0);

  for (int i = 2; i <= n; ++i) {
    int x; cin >> x;
    tree[x].push_back(i);
  }

  dfs(1);
  for (int i = 1; i <= n; ++i)
    cout << subsize[i] << " \n"[i==n];

  return 0;
}