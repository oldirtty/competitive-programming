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
    double l, n;
    scanf("%lf %lf", &l, &n);

    double L = l;
    double area = l * l, raiz3 = sqrt(3);
    double retas = 1;
    double fator_peri = 1;
    for (int i = 1; i <= n; ++i) {
        l /= 3.0;
        area += retas * l * l * raiz3;

        retas *= 4.0;
        fator_peri *= (4.0 / 3.0);
    }
    printf("%.8lf\n", area);
    printf("%.8lf\n", 4.0 * fator_peri * L);
}

int32_t main() {
    clock_t z = clock();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}
