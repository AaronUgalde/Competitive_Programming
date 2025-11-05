#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, s; 
    cin >> n >> s;
    vector<int> A(n);
    for(auto &a : A) cin >> a;
    
    vector<vector<ll>> mn_mx(n, vector<ll>(2));
    for(int i = 0; i < n; i++){
        if(i == 0 or i == n - 1){
            mn_mx[i][0] = mn_mx[i][1] = A[i];
        }else if(A[i] <= s){
            mn_mx[i][0] = 0;
            mn_mx[i][1] = A[i];
        }else{
            mn_mx[i][0] = s;
            mn_mx[i][1] = A[i] - s;
        }
    }

    vector<vector<ll>> memo_mn_mx(n, vector<ll>(2));
    memo_mn_mx[0][0] = memo_mn_mx[0][1] = 0;
    for(int i = 1; i < n; i++){
        memo_mn_mx[i][0] = min(memo_mn_mx[i - 1][0] + mn_mx[i - 1][1] * mn_mx[i][0], memo_mn_mx[i - 1][1] + mn_mx[i - 1][0] * mn_mx[i][0]);
        memo_mn_mx[i][1] = min(memo_mn_mx[i - 1][0] + mn_mx[i - 1][1] * mn_mx[i][1], memo_mn_mx[i - 1][1] + mn_mx[i - 1][0] * mn_mx[i][1]);
    }

    cout << min(memo_mn_mx[n - 1][0], memo_mn_mx[n - 1][1]) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}