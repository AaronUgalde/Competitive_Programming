#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    vector<ll> prefix(n+1);
    prefix[0] = 0;
    for(int i = 0; i<n; i++){
        prefix[i+1] = prefix[i] + (A[i] >= 0 ? A[i] : 0);
    }

    vector<ll> suffix(n+1);
    suffix[n] = 0;
    for(int i = n-1; i >= 0; i--){
        suffix[i] = suffix[i+1] + (A[i] < 0 ? abs(A[i]) : 0);
    }

    ll max_coins = INT_MIN;
    for(int i = 0; i <= n; i++){
        max_coins = max(max_coins, prefix[i] + suffix[i]);
    }

    cout << max_coins << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}