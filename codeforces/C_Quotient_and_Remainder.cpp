#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> Q(n), R(n);
    for(auto &q : Q) cin >> q;
    for(auto &r : R) cin >> r;
    
    sort(all(Q));
    sort(all(R));

    ll r = n;

    auto check = [&](ll m, ll r){
        ll y = r + 1;
        ll x = Q[m] * y + r;
        return y <= k and x <= k;
    };

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll l = -1;
        ll can = false;
        while(r - l > 1){
            ll m = midpoint(l, r);
            if(check(m, R[i])){
                l = m;
                can = true;
            }else{
                r = m;
            }
        }
        if(can) ans++;
        r = l;
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}