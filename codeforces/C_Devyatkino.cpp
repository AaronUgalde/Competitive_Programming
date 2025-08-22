#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

ll mod(ll x, ll mod){
    return ((x % mod) + mod) % mod;
}

void solve(int testcase){
    ll n; cin >> n;
    ll ten = 1;
    ll curr = 0;
    ll nines = 0;
    ll ans = 7; 
    while(n > 0){
        ll x = n % 10;
        ll up = mod(7 - x, 10);
        up += (curr < up);
        if(ten == 1) up = INT_MAX;
        curr += x * ten;
        ll down = mod(curr - (nines + 7*ten), ten*10); 
        ans = min(ans, min(up, down));
        nines += 9*ten;
        ten *= 10;
        n /= 10;
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}