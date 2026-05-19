#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    ll n, s; cin >> n >> s;

    auto check = [&](ll m){
        ll sum = 0;
        ll x = m;
        while(m > 0){
            sum += m % 10;
            m /= 10;
        }
        return abs(sum - x) >= s;
    };

    ll l = -1, r = n + 1;
    while(r - l > 1){
        ll m = midpoint(l, r);
        if(check(m))
            r = m;
        else
            l = m;
    }

    cout << n - l << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}