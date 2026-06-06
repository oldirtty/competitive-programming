/**
 * Contest : CSES Problem Set
 * Problem : 2079 - Finding a Centroid
 * Link    : https://cses.fi/problemset/task/2079
 * Time    : O(N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<int>> tree;
vector<int> subsize;
int n;

void dfs(int u, int p) {
  for (auto& v : tree[u])
    if (v != p) {
      dfs(v,u);
      subsize[u] += subsize[v];
    }
}

int get_centroid(int u, int p) {
  for (auto& v : tree[u]) {
    if (v == p) continue;
    if (subsize[v] * 2 > n) return get_centroid(v, u);
  }
  return u;
}

int main() {
  fastio

  cin >> n;
  tree.assign(n+1, {});
  subsize.assign(n+1, 1);

  for (int i = 2; i <= n; ++i) {
    int a, b;
    cin >> a >> b;

    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  dfs(1, 1);

  cout << get_centroid(1,1) << '\n';

  return 0;
}