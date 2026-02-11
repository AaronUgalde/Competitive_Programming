#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(auto &v : grid){
        for(auto &a : v){
            cin >> a;
        }
    }

    vector<int> i_dirs = {-1, 0, 1, 0};
    vector<int> j_dirs = {0, 1, 0, -1};
    auto dfs = [&](auto &&self,int i, int j) -> ll{
        ll sum = grid[i][j];
        grid[i][j] = -1;
        for(int k = 0; k < 4; k++){
            int n_i = i + i_dirs[k];
            int n_j = j + j_dirs[k];
            if(
                n_i >= 0 and
                n_i < n and
                n_j >= 0 and
                n_j < m and
                grid[n_i][n_j] > 0
            ){
                sum += self(self, n_i, n_j);
            }
        }
        return sum;
    };

    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] > 0) ans = max(ans, dfs(dfs, i, j));
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}