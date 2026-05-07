#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

const int MOD = 1e9 + 7;

ll modexp(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) 
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll mod(ll a, ll b){
    if(a >= 0) return a % b;
    else return b + a;
}

void solve(){
    int n; cin >> n;
    vector<int> X(n);
    for(auto &x : X) cin >> x;

    sort(all(X));
    ll ans = 0;
    for(int i = 0; i < n - 1; i++){
        ans = mod((ans - 1ll * X[i] * (modexp(2, n - i - 1) - 1)) % MOD, MOD);
    }

    for(int i = 0; i < n - 1; i++){
        ans = mod((ans + 1ll * X[n - i - 1] * (modexp(2, n - i - 1) - 1)) % MOD, MOD);
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}