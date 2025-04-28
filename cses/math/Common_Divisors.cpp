#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_X = 1000005;

vector<vector<int>> divisors(MAX_X);

void solve(int testcase){
    int n; cin >> n;
    vector<int> X(n);
    for(int i = 0; i<n; i++) cin >> X[i];

    vector<bool> existent_divisors(MAX_X, false);
    int max_gcd = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<divisors[X[i]].size(); j++){
            if(existent_divisors[divisors[X[i]][j]]){
                max_gcd = max(max_gcd, divisors[X[i]][j]);
            }else{
                existent_divisors[divisors[X[i]][j]] = true;
            }
        }
    }

    cout << max_gcd << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    for(int i = 1; i < MAX_X; i++){
        for(int j = i; j < MAX_X; j += i){
            divisors[j].push_back(i);
        }
    }

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}