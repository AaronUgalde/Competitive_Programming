#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    vector<string> grid(8);
    for(auto &s : grid) cin >> s;

    for(int i = 0; i < 8; i++){
        bool all_red = true;
        for(int j = 0; j < 8; j++){
            if(grid[i][j] != 'R'){
                all_red = false;
                break;
            }
        }
        if(all_red){
            cout << "R" << endl;
            return;
        }
    }

    cout << "B" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}