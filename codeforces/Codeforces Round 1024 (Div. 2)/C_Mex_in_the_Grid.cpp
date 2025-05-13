#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void solve(int testcase){
    int n; cin >> n;
    int cnt = 0;
    int limit = n*n;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    int test = 100;
    int dir = 0;
    int i = 0, j = 0;
    while(cnt < limit){
        for(; i >= 0 && j >= 0 && i < n && j < n; j += dx[dir], i += dy[dir]){
            if(grid[i][j] == -1){
                grid[i][j] = n*n-1-cnt;
                cnt++;
            }else{
                break;
            }
        }
        j -= dx[dir]; i -= dy[dir];
        dir = (dir + 1) % 4;
        i += dy[dir]; j += dx[dir];
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
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