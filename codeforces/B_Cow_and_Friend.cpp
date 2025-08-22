#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    ll n, x; cin >> n >> x;
    set<ll> A;
    for(int i = 0; i<n; i++){
        ll a; cin >> a;
        A.insert(a);
    }

    ll max_hop = *max_element(all(A));
    if(x <= max_hop){
        if(A.count(x)){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
        return;
    }

    ll ans = 1;
    x -= max_hop;
    ans += x/max_hop;
    ans += (x % max_hop > 0);
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