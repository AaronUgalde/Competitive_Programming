#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cout << #x << " = " << (x) << '\n')

const int MOD = 998244353;
ll binpow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n+1);
    ll sum = 0;
    for(int i = 0; i <= n; ++i){
        cin >> a[i];
        sum += a[i];
    }

    ll k = sum / n; 
    ll z = 0;       

    for(int i = 1; i <= n; ++i){
        a[i] -= k;
        if(a[i] <= 0){
            a[0] += a[i]; 
            z++;
        }
        if(a[i] > 1){ 
            cout << 0 << '\n';
            return;
        }
    }

    if(a[0] < 0){
        cout << 0 << '\n';
        return;
    }

    ll x = z - a[0];
    if(x < 0 || x > z){
        cout << 0 << '\n';
        return;
    }

    vector<ll> fact(n+1, 1);
    for(int i = 1; i <= n; ++i) fact[i] = fact[i-1] * i % MOD;

    ll ans = fact[z];
    ans = ans * binpow(fact[z - x], MOD - 2) % MOD;
    ans = ans * fact[n - x] % MOD;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}