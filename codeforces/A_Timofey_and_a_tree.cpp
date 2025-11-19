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
    vector<vector<int>> adj(n);
    vector<pair<int, int>> edges;
    for(int i = 0; i < n - 1; i++){
        int u, v; 
        cin >> u >> v;
        u--; v--;
        edges.emplace_back(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> colors(n);
    for(auto &c : colors) cin >> c;

    auto dfs = [&](auto &&self, int node, int parent) -> bool {
        bool can = true;
        for(auto &child : adj[node]){
            if(child == parent) continue;
            if(colors[child] != colors[node] and parent != -1) {
                return false;
            }
            if(self(self, child, node) == false) can = false;
        }
        return can;
    };

    for(auto &[u, v] : edges){
        if(colors[u] != colors[v]){
            bool can_u = dfs(dfs, u, -1);
            bool can_v = dfs(dfs, v, -1);
            if(can_u or can_v){
                cout << "YES" << endl;
                cout << (can_u ? u + 1 : v + 1);
            }else{
                cout << "NO" << endl;
            }
            return;
        }
    }

    cout << "YES" << endl;
    cout << 1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}