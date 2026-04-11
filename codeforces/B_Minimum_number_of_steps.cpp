#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

const int MOD = 1e9 + 7;

void solve(){
    string s; cin >> s;
    reverse(all(s));
    ll n = sz(s);
    ll cnt = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'b') cnt++;
        else{
            ans = (ans + cnt) % MOD;
            cnt = (cnt * 2) % MOD;
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