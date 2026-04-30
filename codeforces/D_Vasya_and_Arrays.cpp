#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;
    int m; cin >> m;
    vector<int> B(m);
    for(auto &b : B) cin >> b;

    if(accumulate(all(A), 0ll) != accumulate(all(B), 0ll)){
        cout << -1 << endl;
        return;
    }

    map<ll, ll> bucket;
    ll sum = 0; 
    for(auto &a : A){
        sum += a;
        bucket[sum]++;
    }
    sum = 0; 
    for(auto &b : B){
        sum += b;
        bucket[sum]++;
    }

    int ans = 0;
    for(auto &[_, cnt] : bucket){
        if(cnt > 1) ans++;
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