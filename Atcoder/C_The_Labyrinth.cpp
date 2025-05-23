#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int n, m;
const int MAXN = 1000;
vector<string> grid(MAXN);
vector<vector<int>> vis(MAXN, vector<int>(MAXN, -1));
vector<int> components;
int id_component = 0;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(int i, int j){
    vis[i][j] = id_component;
    int total = 1;
    for(int k = 0; k<4; k++){
        int n_i = i + dy[k];
        int n_j = j + dx[k];
        if(n_i < 0 || n_i >= n || n_j < 0 || n_j >= m) continue;
        if(vis[n_i][n_j] == -1 && grid[n_i][n_j] == '.'){
            total += dfs(n_i, n_j);
        }
    }
    return total;
}

void solve(int testcase){
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> grid[i];
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '.' && vis[i][j] == -1){
                components.push_back(dfs(i, j));
                id_component++;
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '*'){
                int val = 0;
                set<int> dif_com;
                for(int k = 0; k<4; k++){
                    int n_i = i + dy[k];
                    int n_j = j + dx[k]; 
                    if(!(n_i >= 0 && n_i < n && n_j >= 0 && n_j < m)) continue;
                    if(grid[n_i][n_j] == '.'){
                        dif_com.insert(vis[n_i][n_j]);
                    }
                }
                for(auto &com : dif_com){
                    val += components[com];
                }
                grid[i][j] = char('0' + (val+1)%10);
            }
        }
    }
    
    for(int i = 0; i<n; i++){
        cout << grid[i] << endl;
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