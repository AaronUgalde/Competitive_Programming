#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(auto &s : grid) cin >> s;

    vector<vector<int>> level_tree(n, vector<int>(m, 0));
    ll cnt = 0;
    for(int level = 1; level <= min(n, m); level++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(
                    (grid[i][j] == '*') and
                    (level == 1 or
                    (
                        i + 1 < n and
                        j - 1 >= 0 and
                        j + 1 < m and
                        level_tree[i + 1][j - 1] == level - 1 and
                        level_tree[i + 1][j] == level - 1 and
                        level_tree[i + 1][j + 1] == level - 1
                    ))
                ){
                    level_tree[i][j] = level;
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}