#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int testcase){
    int h, w; cin >> h >> w;
    string grid[h];
    for(int i = 0; i < h; i++){
        cin >> grid[i];
    }

    int hor[h+1][w+1], ver[h+1][w+1]; 
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            ver[i+1][j+1] = ver[i+1][j] + ver[i][j+1] - ver[i][j];
            hor[i+1][j+1] = hor[i+1][j] + hor[i][j+1] - hor[i][j];
            if(grid[i][j] != '.') continue;
            if(j != w - 1 and grid[i][j+1] == '.') ++hor[i+1][j+1];
            if(i != h - 1 and grid[i+1][j] == '.') ++ver[i+1][j+1];
        }
    }

    int q; cin >> q;
    for(int i = 0; i<q; i++){
        int x1, y1, x2, y2; cin >> y1 >> x1 >> y2 >> x2;
        x1--; y1--;
        int ans = 0;
        ans += hor[y2][x2-1] - hor[y2][x1] - hor[y1][x2-1] + hor[y1][x1];
        ans += ver[y2-1][x2] - ver[y2-1][x1] - ver[y1][x2] + ver[y1][x1];
        cout << ans << '\n';
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