#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int q, x; cin >> q >> x;

    vector<int> cnt(x);
    set<pair<int, int>> cnt_y;

    for(int i = 0; i < x; i++){
        cnt_y.insert({cnt[i], i});
    }

    for(int i = 0; i < q; i++){
        int y; cin >> y; y %= x;
        cnt[y]++;
        cnt_y.erase({cnt[y] - 1, y});
        cnt_y.insert({cnt[y], y});
        cout << cnt_y.begin() -> first * x + cnt_y.begin() -> second << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}