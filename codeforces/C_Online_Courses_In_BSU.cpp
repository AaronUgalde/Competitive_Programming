#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n, k; cin >> n >> k;
    vector<int> main_curses(k);
    for(auto &curse : main_curses) cin >> curse, curse--;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        for(int j = 0; j < t; j++){
            int x; cin >> x; x--;
            adj[i].emplace_back(x);
        }
    }

    vector<int> color(n, 0);
    vector<int> curses_to_take;
    bool cycle = false;
    auto dfs = [&](auto &&self, int u)->void{
        if(color[u] == 0){
            color[u] = 1;
            for(auto &v : adj[u]){
                self(self, v);
            }
            curses_to_take.emplace_back(u);
            color[u] = 2;
        }else if(color[u] == 1){
            cycle = true;
        }
    };

    for(auto &curse : main_curses){
        dfs(dfs, curse);
    }

    if(cycle){
        cout << -1 << endl;
        return;
    }

    cout << sz(curses_to_take) << endl;

    for(auto &curse : curses_to_take){
        cout << curse + 1 << ' ';
    }

    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}