#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, q; cin >> n >> q;
    vector<vector<bool>> is_lava(2, vector<bool>(n, false));

    int number_of_bloks = 0; 
    for(int i = 0; i < q; i++){
        int r, c; cin >> r >> c; r--; c--;
        is_lava[r][c] = !is_lava[r][c];
        int r_1 = (r + 1) % 2;
        for(int j = max(0, c - 1); j <= min(n - 1, c + 1); j++){
            if(is_lava[r_1][j]){
                number_of_bloks += (is_lava[r][c] ? 1 : -1);
            }
        }

        cout << (number_of_bloks == 0 ? "Yes" : "No") << endl;
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