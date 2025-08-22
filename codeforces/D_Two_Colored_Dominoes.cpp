#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(auto &s : grid) cin >> s;

    vector<int> b_rows(n, 0), b_columns(m, 0);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 'U'){
                if(b_rows[i] <= 0){
                    b_rows[i]++;
                    grid[i][j] = 'W';
                    grid[i+1][j] = 'B';
                }else{
                    b_rows[i]--;
                    grid[i][j] = 'B';
                    grid[i+1][j] = 'W';
                }
            }else if(grid[i][j] == 'L'){
                if(b_columns[j] <= 0){
                    b_columns[j]++;
                    grid[i][j] = 'W';
                    grid[i][j+1] = 'B';
                }else{
                    b_columns[j]--;
                    grid[i][j] = 'B';
                    grid[i][j+1] = 'W';
                }
            }
        }
    }
    
    for(int i = 0; i<n; i++){
        if(b_rows[i] != 0){
            cout << -1 << endl;
            return;
        }
    }

    for(int i = 0; i<m; i++){
        if(b_columns[i] != 0){
            cout << -1 << endl;
            return;
        }
    }

    for(int i = 0; i<n; i++){
        cout << grid[i] << endl;
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