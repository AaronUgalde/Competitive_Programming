#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(auto &s : grid) cin >> s;

    vector<bool> zero_row(n, false), zero_col(m, false);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '0'){
                zero_row[i] = zero_col[j] = true;
            }else{
                if(i > 0 && j > 0 && zero_row[i] && zero_col[j]){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }

    cout << "YES" << endl;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}