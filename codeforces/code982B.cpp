/**
 * Contest : Codeforces Round 484 (Div. 2)
 * Problem : B - Bus of Characters
 * Link    : https://codeforces.com/contest/982/problem/B
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int> ;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

int main() {
    fastio

    int n; cin >> n;
    vector<int> amount (n,0);
    priority_queue<pii, vector<pii>, greater<pii>> free;
    priority_queue<pii> occupied;

    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        free.push({x, i});
    }

    string str; // 0 = introvertido
    cin >> str; // 1 = extrovertido

    vector <int> ans;
    for (auto &c : str) {
        if (c == '0') {
            auto [w, id] = free.top();
            free.pop();

            ans.push_back(id);
            occupied.push({w,id});
        }
        else {
            auto [w, id] = occupied.top();
            occupied.pop();

            ans.push_back(id);
        }
    }

    for (auto &i : ans)
        cout << i << ' ';
    cout << endl;

    return 0;
}