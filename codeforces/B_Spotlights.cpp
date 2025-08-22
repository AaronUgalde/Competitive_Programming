#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(auto &f : grid)
        for(auto &c : f)
            cin >> c;

    int ans = 0;


    for(int i = 0; i<n; i++){
        int first = -1, last = -1, cnt = 0;
        for(int j = 0; j<m; j++){
            if(grid[i][j] != 1) continue;
            if(last == -1){
                first = j;
                last = j;
            }else{
                last = j;
            }
            cnt++;
        }
        if(first == -1) continue;
        int totaldouble = last - first + 1 - cnt;
        int totalone = first + m - last - 1;
        ans += totaldouble*2 + totalone;
    }


    for(int i = 0; i<m; i++){
        int first = -1, last = -1, cnt = 0;
        for(int j = 0; j<n; j++){
            if(grid[j][i] != 1) continue;
            if(last == -1){
                first = j;
                last = j;
            }else{
                last = j;
            }
            cnt++;
        }
        if(first == -1) continue;
        int totaldouble = last - first + 1 - cnt;
        int totalone = first + n - last - 1;
        ans += totaldouble*2 + totalone;
    }

    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}