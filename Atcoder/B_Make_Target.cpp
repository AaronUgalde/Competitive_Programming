#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve(int testcase){
    int n; cin >> n;
    vector<string> grid(n, string(n, ' '));
    int x = 0, y = 0;
    for(int i = 0; i < n/2 + (n%2); i++){
        x = 0 + i; y = 0 + i;
        int upper = n - i, lower = 0 + i;
        for(int j = 0; j<4; j++){
            for(; x < upper && x >= lower && y < upper && y >= lower; x += dx[j], y += dy[j]){
                grid[x][y] = (i % 2 == 0 ? '#' : '.');
            }
            x -= dx[j]; y -= dy[j];
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