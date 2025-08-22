#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<string> grid(n, string(n, ' '));
    for(auto &s : grid) cin >> s;

    char color_s_d = grid[1][0];
    char color_s_r = grid[0][1];
    char color_f_l = grid[n-1][n-2];
    char color_f_d = grid[n-2][n-1];

    vector<pair<int, int>> flips;
    if(color_s_d == color_s_r){
        if(color_f_l == color_s_d){
            flips.emplace_back(n, n-1);
        }
        if(color_f_d == color_s_d){
            flips.emplace_back(n-1, n);
        } 
    }else{
        if(color_f_d == color_f_l){
            if(color_f_l == color_s_d){
                flips.emplace_back(2, 1);
            }else{
                flips.emplace_back(1, 2);
            }   
        }else{
            if(color_f_d == color_s_d){
                flips.emplace_back(n-1, n);
                flips.emplace_back(1, 2);
            }else{
                flips.emplace_back(n-1, n);
                flips.emplace_back(2, 1);
            }
        }
    }

    cout << flips.size() << endl;
    for(int i = 0; i<flips.size(); i++){
        cout << flips[i].first << ' ' << flips[i].second << endl;
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