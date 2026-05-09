#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    ll n; cin >> n;
    vector<ll> X(n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        ans += b * n - a;
        X[i] = (a - b);
    }

    sort(all(X), greater<int>());
    for(ll i = 0; i < n; i++){
        ans += X[i] * (i + 1);
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