#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    ll l, r, x, y;
    cin >> l >> r >> x >> y;
    if(y % x != 0){
        cout << 0 << endl;
        return;
    }
    ll n = y / x;
    ll ans = 0;
    for(ll c = 1; c * c <= n; c++){
        if(n % c != 0) continue;
        ll d = n / c;
        if(c * x >= l and c * x <= r and d * x >= l and d * x <= r and gcd(c, d) == 1){
            if(c == d) ans++;
            else ans += 2;
        }
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