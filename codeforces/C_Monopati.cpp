#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    vector<int> up(n);
    vector<int> down(n);
    for(auto &x : up) cin >> x;
    for(auto &x : down) cin >> x;

    vector<pair<int, int>> pf(n + 1, {INT_MAX, INT_MIN});
    for(int i = 0; i < n; i++){
        pf[i + 1].first = min(pf[i].first, up[i]);
        pf[i + 1].second = max(pf[i].second, up[i]);
    }

    vector<pair<int, int>> sf(n + 1, {INT_MAX, INT_MIN});
    for(int i = n - 1; i >= 0; i--){
        sf[i].first = min(sf[i + 1].first, down[i]);
        sf[i].second = max(sf[i + 1].second, down[i]);
    }

    ll ans = 0;
    int last_l = 0;
    int last_r = 2 * n + 1;
    for(int i = 0; i < n; i++){
        int l = min(pf[i + 1].first, sf[i].first);
        int r = max(pf[i + 1].second, sf[i].second);
        ans += 1ll * l * (2 * n - r + 1);
        ans -= 1ll * min(l, last_l) * (2 * n - max(r, last_r) + 1);    
        last_l = l;
        last_r = r;  
    }

    
    cout << ans << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}