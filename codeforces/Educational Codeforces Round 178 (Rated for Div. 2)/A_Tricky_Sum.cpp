#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    ll n; cin >> n;
    ll ans = (n + 1) * n / 2; 
    for(int mask = 1; mask <= n; mask <<= 1){
        ans -= 2*mask;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}