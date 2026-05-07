#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

const ll MOD = 1e9 + 7;

ll mod(ll a, ll b){
    if(a > 0) return a % b;
    else return b + a;
}

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

void solve(){
    ll l, r, k; cin >> l >> r >> k;
    ll cnt = 0;
    for(int i = 0; i < 10; i++){
        if(1ll * i * k < 10) cnt++;
    }

    cout << mod(modexp(cnt, r) - modexp(cnt, l), MOD) % MOD << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}