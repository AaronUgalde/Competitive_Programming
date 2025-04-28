#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 6;

ll binpow(ll a, ll b, ll MOD){
    a %= MOD;
    ll res = 1;
    while(b > 0){
        if(b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve(int testcase){
    ll a, b, c; cin >> a >> b >> c;
    ll pow = binpow(b, c, MOD2);
    cout << binpow(a, pow, MOD1) << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}