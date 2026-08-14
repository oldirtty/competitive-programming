/**
 * Contest : SPOJ
 * Problem : D-query
 * Link    : https://www.spoj.com/problems/DQUERY/
 * Time    : O((N + Q) √N)
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

const int N = 1e6+1;
int n, m, queries, distinct = 0;
int cnt[N];

struct Query {
    int l, r, id, ans;
};

void add(int val) {
    cnt[val]++;
    if (cnt[val] == 1) distinct++;
}

void remove(int val) {
    cnt[val]--;
    if (cnt[val] == 0) distinct--;
}

void solve() {
    cin >> n;
    m = sqrt(n) + 1;

    int v[n];
    for (int i = 0; i < n; ++i) cin >> v[i];

    cin >> queries;
    vector<Query> q(queries);
    for (int i = 0; i < queries; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].l--; q[i].r--;
        q[i].id = i;
        q[i].ans = 0;
    }
    sort(q.begin(), q.end(), [&](Query a, Query b) {
        if (a.l / m != b.l / m) return a.l < b.l;
        return a.r < b.r;
    }); // O(Q logQ)

    int x = 0, y = 0;
    for (auto &[l, r, idx, ans] : q) {
        while (y <= r) {
            add(v[y]);
            y++;
        }
        while (y > r + 1) {
            y--;
            remove(v[y]);
        }

        while (x < l) {
            remove(v[x]);
            x++;
        }
        while (x > l) {
            x--;
            add(v[x]);
        }

        ans = distinct;
    }

    sort(q.begin(), q.end(), [](Query a, Query b) {
        return a.id < b.id;
    }); // O(Q logQ)

    for (const auto &i : q)
        cout << i.ans << endl;
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
