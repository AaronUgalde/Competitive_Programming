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

    vector<int> memo(n, -1);

    auto dp = [&](auto &&self, int i) -> int{
        if(i == n){
            return 0;
        }else if(i > n){
            return INT_MAX;
        }else if(memo[i] != -1){
            return memo[i];
        }
        memo[i] = min(self(self, i + 1) + 1, self(self, i + A[i] + 1));
        return memo[i];
    };
    
    cout << min(dp(dp, 0) + 1, dp(dp, 0)) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}