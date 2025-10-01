#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, m, k; cin >> n >> m >> k;
    vector<string> grid(n);
    for(auto &s : grid) cin >> s;

    vector<string> vis = grid;

    vector<vector<pair<int, int>>> lakes;
    vector<int> x_dir = {0, 1, 0, -1};
    vector<int> y_dir = {1, 0, -1, 0};

    auto dfs = [&](auto &&self, int x, int y, vector<pair<int, int>> &lake) -> bool{
        if(x == 0 || x == n - 1 || y == 0 || y == m - 1){
            vis[x][y] = '*';
            lake.emplace_back(x, y);
            return false;
        }
        vis[x][y] = '*';
        lake.emplace_back(x, y);

        for(int i = 0; i < 4; i++){
            int new_x = x + x_dir[i];
            int new_y = y + y_dir[i];
            if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
            if(grid[new_x][new_y] == '.' && vis[new_x][new_y] == '.'){
                if(!self(self, new_x, new_y, lake)){
                    return false;
                }
            }
        }
        return true;
    };

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' && vis[i][j] == '.'){
                vector<pair<int, int>> lake;
                if(dfs(dfs, i, j, lake)) lakes.push_back(lake);
            }
        }
    }

    sort(all(lakes), [&](const vector<pair<int, int>> &a, const vector<pair<int, int>> &b){
        return sz(a) > sz(b);
    });

    int sum_lakes = 0;
    for(int i = 0; i < sz(lakes) - k; i++){
        sum_lakes += sz(lakes[sz(lakes) - 1 - i]);
    }

    cout << sum_lakes << endl;


    for(int i = 0; i < sz(lakes) - k; i++){
        for(const auto &p : lakes[sz(lakes) - 1 - i]){
            grid[p.first][p.second] = '*';
        }
    }

    for(auto &s : grid) cout << s << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}
