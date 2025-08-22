#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    ll n, x; cin >> n >> x;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    sort(all(A));
    ll ans = 0, last = 0;
    for(int i = 0; i<n; i++){
        ll available = x - last;
        if(A[i] > available) continue;
        ll res = available - A[i];
        ans += res/(i+1) + 1;
        last += A[i];
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