#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

vector<int> i_directions = {1, 0, -1, 0};
vector<int> j_directions = {0, 1, 0, -1};
int component[100001] = {};
int i;

int dfs(int x, int y, vector<string> &grid, vector<vector<int>> &visited){
    visited[x][y] = i;
    int ans = 0;
    for(int k = 0; k<4; k++){
        int x2 = x + i_directions[k], y2 = y + j_directions[k];
        if(grid[x2][y2] == '*'){
            ans++;
        }else if(!visited[x2][y2]){
            ans += dfs(x2, y2, grid, visited);
        }
    }
    return ans;
}

void solve(int testcase){
    int n, m, k; cin >> n >> m >> k;
    vector<string> grid(n);
    for(auto &s : grid) cin >> s; 

    vector<vector<int>> visited(n, vector<int>(m, 0));
    for(i = 1; i<=k; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        if(visited[x][y] == 0){
            int ans = dfs(x, y, grid, visited);
            cout << ans << endl;
            component[visited[x][y]] = ans;
        }
        else{
            cout << component[visited[x][y]] << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}