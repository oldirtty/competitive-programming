#include <bits/stdc++.h>
using namespace std;

#define int long long
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

set<int> ans;
set<string> done;
int B = 2e8;
void solve() {
    int a, b;
    cin >> a >> b;


}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    clock_t z = clock();

    int pot = 1;
    for (int i = 1, b = 10; i <= B; ++i) {
        if (i % b == 0) {
            pot++;
            b *= 10;
        }
        string num = to_string(i);
        sort(num.begin(), num.end());
        if (done.count(num)) continue;
        done.insert(num);

        int soma = 0;
        for (auto& n : num) {
            int x = n - '0';
            soma += pow(x, pot);
        }
        if (soma != i) continue;

        dbg(i);
        ans.insert(i);
    }

    int t = 1;
    // cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}
