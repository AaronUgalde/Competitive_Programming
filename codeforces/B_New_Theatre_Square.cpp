#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<string> grid(n, string(m, ' '));
    for(auto &s : grid) cin >> s;

    int one = 0;
    int two = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '.'){
                if(j + 1 == m) one++;
                else if(grid[i][j+1] == '*') one++;
                else two++, grid[i][j+1] = '*';
            }
        }
    }

    y = min(y, 2 * x);
    cout << one * x + two * y << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}