/**
 * Contest : Codeforces Round 828 (Div. 3)
 * Problem : 1744C. Traffic Light
 * Link    : https://codeforces.com/problemset/problem/1744/C
 */

#include <bits/stdc++.h>
using namespace std;

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define endl '\n'

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

void solve() {
    int n;
    char cor;
    cin >> n >> cor;

    string s; cin >> s;
    if (cor == 'g') {
        cout << 0 << endl;
    }
    else {
        vector<int> pref(n + 1);
        for (int i = 1; i <= n; ++i)
            pref[i] = pref[i - 1] + (s[i - 1] == 'g');

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            char c = s[i - 1];
            if (c != cor) continue;

            int dist = -1;
            auto it = lower_bound(pref.begin() + i, pref.end(), pref[i] + 1);
            if (it == pref.end()) {
                it = lower_bound(pref.begin(), pref.end(), 1);
                dist = n - i + it - pref.begin();
            }
            else dist = it - pref.begin() - i;
            ans = max(ans, dist);
        }
        cout << ans << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    clock_t z = clock();

    int t = 1;
    cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}
