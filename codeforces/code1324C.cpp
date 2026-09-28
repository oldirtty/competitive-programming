/**
 * Contest : Codeforces Round 627 (Div. 3)
 * Problem : 1324C. Frog Jumps
 * Link    : https://codeforces.com/problemset/problem/1324/C
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
    string s; cin >> s;
    int n = s.size();
    int last = 0, d = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'R') {
            d = max(d, i - last);
            last = i;
        }
    }
    d = max(d, n + 1 - last);
    cout << d << endl;
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
