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
    vector<bool> ans(n);
    vector<int> v(n);

    for(auto& i : v) cin >> i;

    // prefix
    ans[0] = ans[n-1] = true;
    for (int i = 1, mini = v[0]; i < n-1; ++i) {
        if (v[i] < mini) {
            ans[i] = true;
            mini = v[i];
        }
    }

    for (int i = n-1, maxi = v[n-1]; i > 0; --i) {
        if (v[i] > maxi) {
            ans[i] = true;
            maxi = v[i];
        }
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i];
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
