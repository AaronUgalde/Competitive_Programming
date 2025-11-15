#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    ll b; cin >> b;
    ll cnt = 0;
    ll ans = 0;
    for(ll a = 1; a * a <= b; a++){
        if(b % a == 0){
            ans++;
            if(b / a != a) ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}