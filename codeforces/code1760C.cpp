/**
 * Contest : Codeforces Round 835 (Div. 4)
 * Problem : 1760C. Advantage
 * Link    : https://codeforces.com/problemset/problem/1760/C
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
    int n; cin >> n;
    int v[n];
    int maior = 0, qseMaior = 0;
    for (auto& i : v) {
        cin >> i;
        if (i >= maior) {
            qseMaior = maior;
            maior = i;
        }
        else if (i >= qseMaior) {
            qseMaior = i;
        }
    }

    for (auto& i : v) {
        if (i == maior)
            cout << i - qseMaior << " ";
        else cout << i - maior << " ";
    }
    cout << endl;
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
