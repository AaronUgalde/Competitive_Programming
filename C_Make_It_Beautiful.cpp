#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    ll n, k; cin >> n >> k;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    ll ans = 0;
    for(ll i = 0; i < 60; i++){
        ll mask = 1ll << i;
        for(ll j = 0; j < n; j++){
            if((A[j] & mask) == false and k >= mask){
                ans++;
                k -= mask;
            }else if(A[j] & mask){
                ans++;
            }
        }
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