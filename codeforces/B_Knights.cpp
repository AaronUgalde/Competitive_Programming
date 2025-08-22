#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<string> board(n, string(n, '.'));
    
    auto neighbours = [&](int x, int y){
        vector<pair<int, int>> neighbours(8);
        vector<pair<int, int>> final_neighbours;
        neighbours[0] = {x-2, y-1};
        neighbours[1] = {x-2, y+1};
        neighbours[2] = {x+2, y+1};
        neighbours[3] = {x+2, y-1};
        neighbours[4] = {x-1, y-2};
        neighbours[5] = {x-1, y+2};
        neighbours[6] = {x+1, y+2};
        neighbours[7] = {x+1, y-2};
        for(auto &[a, b]: neighbours){
            if(!(a < 0 || a >= n || b < 0 || b >= n || board[a][b] != '.')){
                final_neighbours.emplace_back(a, b);
            }
        }
        return final_neighbours;
    };

    map<char, char> contrary_color = {{'W', 'B'}, {'B', 'W'}};

    auto dfs = [&](auto &&self, int x, int y, char color) -> void {
        board[x][y] = color;
        for(auto &[a, b] : neighbours(x, y)){
            self(self, a, b, contrary_color[color]);
        }
    };

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(board[i][j] == '.'){
                dfs(dfs, i, j, 'W');
            }
        }
    }

    for(auto &s : board) cout << s << endl; 
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}
