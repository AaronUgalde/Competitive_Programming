#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<string> grid(n);
    for(auto &s : grid) cin >> s;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j] == '1' && (i + 1 < n && grid[i+1][j] == '0') && (j+1 < n && grid[i][j+1] == '0')){
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}