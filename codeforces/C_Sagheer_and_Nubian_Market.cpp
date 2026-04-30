#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    ll n, s; cin >> n >> s;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    auto check = [&](ll m){
        vector<ll> cost(n);
        for(ll i = 0; i < n; i++){
            cost[i] = A[i] + (i + 1) * m;
        }
        sort(all(cost));
        return accumulate(cost.begin(), cost.begin() + m, 0ll);
    };

    ll l = -1, r = n + 1;
    ll total = 0;
    while(r - l > 1){
        ll m = midpoint(l, r);
        ll cost_of_m = check(m);
        if(cost_of_m <= s){
            l = m;
            total = cost_of_m;
        }else{
            r = m;
        }
    }

    cout << l << ' ' << total << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}