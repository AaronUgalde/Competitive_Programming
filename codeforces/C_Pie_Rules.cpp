#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    ll n; cin >> n;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;
    reverse(all(A));

    vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
    const int BOB = 1;
    const int ALICE = 0;
    int turn = BOB;
    for(int i = 0; i<n; i++){
        dp[i+1][BOB] = max(A[i] + dp[i][ALICE],-A[i] + dp[i][BOB]); 
        dp[i+1][ALICE] = min(-A[i] + dp[i][BOB],A[i] + dp[i][ALICE]);
    }
    ll equal = (accumulate(all(A), 0ll) - dp[n][BOB])/2;
    cout << equal << ' ' << equal + dp[n][BOB] << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}