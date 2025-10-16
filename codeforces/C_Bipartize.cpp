#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')
#define red first
#define blue second

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for(auto &[u, v] : edges){
        cin >> u >> v; u--; v--;
    }

    int min_operations = INT_MAX;
    for(int mask = 0; mask < (1 << n); mask++){
        int operations = 0;
        for(auto &[u, v] : edges){
            if((1 & (mask >> u)) == (1 & (mask >> v))){
                operations++;
            }
        }
        min_operations = min(min_operations, operations);
    }

    cout << min_operations << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
   // cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}