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
    vector<vector<int>> groups(n, vector<int>(n));
    int cnt = 1;
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++, cnt++){
            groups[(j % 2 == 0 ? i : n - 1 - i)][j] = cnt;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << groups[i][j] << ' ';
        }
        cout << endl;
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