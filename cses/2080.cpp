/**
 * Contest : CSES Problem Set
 * Problem : 2080 - Fixed-Length Paths I
 * Link    : https://cses.fi/problemset/task/2080
 * Time    : O(N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<int>> tree;
vector<int> subsize;
int n, k;

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

  cin >> n >> k;
  tree.assign(n+1, {});
  subsize.assign(n+1, 1);

  for (int i = 2; i <= n; ++i) {
    int a, b;
    cin >> a >> b;

    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  dfs(1, 1);

  auto centroid = get_centroid(1,1);
  subsize.assign(n+1,1);
  dfs(centroid, centroid);

  cerr << "centroid = " << centroid << endl;
  int cnt = 0;
  for (auto& v : tree[centroid]) {
    cerr << subsize[v] << endl;
    cnt += subsize[v];
  }

  cout << cnt << '\n';

  return 0;
}