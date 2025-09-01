#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())



void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<vector<ll>> A(n, vector<ll>(m));
    vector<vector<ll>> B(n, vector<ll>(m));
    for(auto &v : A)
        for(auto &a : v) cin >> a;
    for(auto &v : B)
        for(auto &b : v) cin >> b;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(i - 1 >= 0 && !((min(A[i - 1][j], B[i - 1][j]) < min(A[i][j], B[i][j]) && max(A[i - 1][j], B[i - 1][j]) < max(A[i][j], B[i][j])))
            || j - 1 >= 0 && !((min(A[i][j -  1], B[i][j - 1]) < min(A[i][j], B[i][j]) && max(A[i][j - 1], B[i][j - 1]) < max(A[i][j], B[i][j])))) {
                cout << "Impossible" << endl;
                return;
            }
        }
    }

    cout << "Possible" << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}