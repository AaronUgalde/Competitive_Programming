#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')
vector<int> dir_i = {1, 0, -1, 0};
vector<int> dir_j = {0, 1, 0, -1};

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(auto &s : grid) cin >> s;

    auto check = [&](int i, int j){
        return (i >= 0 && i < n && j >= 0 && j < m);
    };

    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'E'){
                q.emplace(i, j);
            }
        }
    }

    string A = "^<v>";
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int ni = i  + dir_i[dir];
            int nj = j  + dir_j[dir];
            if(!check(ni, nj)) continue;
            if(grid[ni][nj] != '.') continue;
            grid[ni][nj] = A[dir];
            q.emplace(ni, nj);
        }
    }

    for(auto &s : grid){
        cout << s << endl;
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