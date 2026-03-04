#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

const ll MOD = 1e9 + 7;

ll binpow(int a, int b){
    ll x = a;
    ll res = 1;
    while(b > 0){
        if(b & 1){
            res = res * x % MOD;
        }
        b >>= 1;
        x = x * x % MOD;
    }
    return res;
}

void solve(int testcase){
    ll t; cin >> t;
    vector<int> N(t), K(t);
    for(auto &n : N) cin >> n;
    for(auto &k : K) cin >> k;

    for(int i = 0; i < t; i++){
        cout << binpow(2, K[i]) << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}