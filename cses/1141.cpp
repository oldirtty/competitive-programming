/**
 * Contest : CSES Problem Set
 * Problem : 1141 - Playlist
 * Link    : https://cses.fi/problemset/task/1141
 * Time    : O(N logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  vector<int> songs(n);
  for (auto& i : songs) cin >> i;

  int ans = 0;
  set<int> id;
  for (int l = 0, r = 0; l < n; ++l) {
    while (r < n) {
      ans = max(ans, (int)id.size());

      if (id.count(songs[r])) break;
      id.insert(songs[r++]);
    }

    ans = max(ans, (int)id.size());
    id.erase(songs[l]);
  }
  cout << ans << '\n';

  return 0;
}