  /**
  * Contest : Beecrowd
  * Problem : Decifra
  * Link    : https://judge.beecrowd.com/pt/problems/view/2464
  * Time    : O(|S|)
  */

  #include <bits/stdc++.h>
  using namespace std;
  using ll = long long;

  #define fastio ios::sync_with_stdio(0); cin.tie(0);

  int main() {
    fastio

    map<char,char> mp;
    string t, s;
    cin >> t >> s;

    for (int i = 0; i < t.size(); ++i)
      mp['a'+i] = t[i];

    for (auto& c : s)
      cout << mp[c];
    cout << '\n';

    return 0;
  }