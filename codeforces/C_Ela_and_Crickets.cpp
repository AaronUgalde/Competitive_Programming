#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    map<int, int> coordinates_x;
    map<int, int> coordinates_y;
    for(int i = 0; i < 3; i++){
        int x, y; cin >> x >> y;
        coordinates_x[x]++;
        coordinates_y[y]++;
    }

    int x, y; cin >> x >> y;
    int repeated_x, repeated_y;
    for(auto &[key, frec] : coordinates_x){
        if(frec == 2) repeated_x = key;
    }
    for(auto &[key, frec] : coordinates_y){
        if(frec == 2) repeated_y = key;
    }

    vector<pair<int, int>> corners = {{1, 1}, {n, n}, {1, n}, {n, 1}};
    for(auto &[i, j] : corners){
        if(i == repeated_x and j == repeated_y){
            if(repeated_x == x or repeated_y == y){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
            return;
        }
    }

    if(repeated_x % 2 == x % 2 or repeated_y % 2 == y % 2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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