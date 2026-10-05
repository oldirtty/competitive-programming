/**
 * Contest : Codeforces Round 223 (Div. 1)
 * Problem : 380A. Sereja and Prefixes
 * Link    : https://codeforces.com/problemset/problem/380/A
 */

#include <bits/stdc++.h>
using namespace std;

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define endl '\n'
#define int long long

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
    const int LIM = 1e5+1;
    int q; cin >> q;
    int n = 0;

    vector<int> a;
    vector<int> st(q), en(q), type(q), aux(q);
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        type[i] = op;
        st[i] = n;
        if (op == 1) {

            int x; cin >> x;
            aux[i] = x;
            n++;
            if (a.size() < LIM) a.push_back(x);
        }
        else {
            int l, c; cin >> l >> c;
            aux[i] = l;
            for (int k = 0; k < c && a.size() < LIM; k++)
                for (int j = 0; j < l && a.size() < LIM; j++)
                    a.push_back(a[j]);
            n += l * c;
        }
        en[i] = n;
    }

    cin >> q;
    while (q--) {
        int x; cin >> x;
        int i = lower_bound(en.begin(), en.end(), x) - en.begin();
        if (type[i] == 1) cout << aux[i] << " ";
        else {
            int idx = x - 1 - st[i];
            cout << a[idx % aux[i]] << " ";
        }
    }
    cout << endl;
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
