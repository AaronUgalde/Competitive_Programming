#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    string a,b,c;
    cin >> a >> b >> c;
    int na = (int)a.size();
    int nb = (int)b.size();
    vector<vector<int>> dp(na+1, vector<int>(nb+1, INT_MAX));
    dp[0][0] = 0;
    for(int i = 0; i <= na; ++i){
        for(int j = 0; j <= nb; ++j){
            if(dp[i][j] == INT_MAX) continue;
            int pos = i + j;
            if(i < na){
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + (a[i] != c[pos] ? 1 : 0));
            }
            if(j < nb){
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + (b[j] != c[pos] ? 1 : 0));
            }
        }
    }
    cout << dp[na][nb] << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}