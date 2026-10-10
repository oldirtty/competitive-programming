/**
 * Contest : Codeforces Round 364 (Div. 2)
 * Problem : 701C. They Are Everywhere
 * Link    : https://codeforces.com/problemset/problem/701/C
 */

#include <bits/stdc++.h>
using namespace std;

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define endl '\n'

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    set<char> uniq;
    for (auto &c : s) uniq.insert(c);

    unordered_map<char, int> pokemon;
    int total = uniq.size(), ans = n;
    for (int l = 0, r = 0; l < n;) {
        while (r < n && pokemon.size() < total)
            pokemon[s[r++]]++;

        if (pokemon.size() == total)
            ans = min(ans, r - l);

        pokemon[s[l]]--;
        if (!pokemon[s[l]])
            pokemon.erase(pokemon.find(s[l]));
        l++;
        if (pokemon.size() == total)
            ans = min(ans, r - l);
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    clock_t z = clock();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}
