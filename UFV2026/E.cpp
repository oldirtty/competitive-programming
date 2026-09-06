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
    vector<string> v(201);

    char num = '0';
    char letra = 'a';
    for (int i = 0; i < 200; ++i) {
        v[i] = letra;
        if (num != '0') v[i] += num;
        letra++;
        if (letra > 'z') {
            letra = 'a';
            num++;
        }
    }

    int n; cin >> n;
    vector<string> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (i == j)
                ans.push_back(v[i] + "^2");
            else
                ans.push_back("2" + v[i] + v[j]);
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if (i < ans.size() - 1) cout << " + ";
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
