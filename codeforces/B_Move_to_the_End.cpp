#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    vector<ll> suffix(n + 1); suffix[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        suffix[i] = A[i] + suffix[i + 1];
    }

    vector<int> bestNumTilK(n + 1); bestNumTilK[0] = 0;
    for(int i = 1; i<=n; i++){
        bestNumTilK[i] = max(bestNumTilK[i - 1], A[i - 1]);
    }

    for(int i = 1; i <= n; i++){
        //cout << "suf: " << suffix[n - i] << " a: " << A[n - i] << " best: " << bestNumTilK[n -i] << '\n';
        ll sum = suffix[n - i];
        if(bestNumTilK[n - i] > A[n - i]){
            sum = sum - A[n - i] + bestNumTilK[n - i];
        }
        cout << sum << ' ';
    }

    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}