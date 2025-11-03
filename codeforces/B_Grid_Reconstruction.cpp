#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

int mod(int x, int y){
    if(x % y < 0) return y + x;
    else return x % y;
}

void solve(int testcase){
    int n; cin >> n;
    vector<vector<int>> ans(2, vector<int>(n));
    for(int i = 0; i < n; i++){
        int t;
        if(i % 2 == 0){
            t = 2 * n - i;
        }else{
            t = 2 * ((i / 2) + 1);
        }
        ans[0][i] = t;
        ans[1][mod(i - 1, n)] = t - 1;
    }

    for(auto &v : ans){
        for(auto &a : v){
            cout << a << ' ';
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}