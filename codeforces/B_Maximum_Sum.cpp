#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

const ll MOD = 1e9 + 7;

ll mod(ll x, ll m) {
    return ((x % m) + m) % m;
}

void solve(int testcase){
    ll n, k; cin >> n >> k;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    ll curr = A[0];
    ll mx = A[0];
    for(int i = 1; i<n; i++){
        mx = max(A[i], mx + A[i]);
        curr = max(curr, mx);
    }

    ll sum = mod(accumulate(all(A), 0ll), MOD);

    if(curr < 0){
        cout << sum << endl;
        return;
    }

    while(k){
        sum += curr;
        curr = (curr * 2) % MOD;
        k--;
    }

    cout << mod(sum, MOD) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}