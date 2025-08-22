#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

const int MOD = 1e9 + 7; 

ll bin_pow(ll a, ll b){
    a %= MOD;
    long long res = 1;
    while(b > 0){
        if(b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve(int testcase){
    ll n; cin >> n;
    ll childs = (1ll << n) - 2;
    ll ans = 6 * bin_pow(4, childs) % MOD;

    cout << ans % MOD << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}