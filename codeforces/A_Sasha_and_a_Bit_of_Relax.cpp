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
    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    vector<ll> prefix(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefix[i + 1] = prefix[i] ^ A[i];
    }

    map<ll, pair<ll, ll>> bucket;
    for(int i = 0; i <= n; i++){
        if(i % 2 == 0){
            bucket[prefix[i]].first++;
        }else{
            bucket[prefix[i]].second++;
        }
    }

    ll ans = 0;
    for(int i = 0; i <= n; i++){
        if(i % 2 == 0){
            ans += bucket[prefix[i]].first - 1;
            bucket[prefix[i]].first--;
        }else{
            ans += bucket[prefix[i]].second - 1;
            bucket[prefix[i]].second--;
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