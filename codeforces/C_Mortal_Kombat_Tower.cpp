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

    const int TURN_ME = 0;
    const int TURN_FRIEND = 1;
    vector<vector<int>> memo(2, vector<int>(n+2, -1));
    auto dp = [&](auto &&self, int turn, int i) -> int {
        if(i >= n) return 0;
        if(memo[turn][i] != -1) return memo[turn][i];
        if(turn == TURN_ME){
            memo[turn][i] = min(self(self, TURN_FRIEND, i+1), self(self, TURN_FRIEND, i+2));
        }else{
            memo[turn][i] = min(self(self, TURN_ME, i+1) + (A[i]==1), self(self, TURN_ME, i+2) + (A[i]==1) + (i+1 < n && A[i+1] == 1));   
        }
        return memo[turn][i];
    };

    cout << dp(dp, TURN_FRIEND, 0) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}