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

    int max_ll = 1;
    int min_rl = 2 * n;
    int max_lr = 1;
    int min_rr = 2 * n;
    for(int i = 0; i < n; i++){
        int l = min(pf[i + 1].first, sf[i].first);
        int r = max(pf[i + 1].second, sf[i].second);
        if(l > max_ll){
            max_ll = l;
            min_rl = r;
        }
        if(r < min_rr){
            max_lr = l;
            min_rr = r;
        }
    }

    
    cout << "max_l: " << max_l << endl;
    cout << max_l * (2 * n - min_r + 1) << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}