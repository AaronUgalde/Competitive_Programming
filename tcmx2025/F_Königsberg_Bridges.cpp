#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    int time = 0;
    vector<int> low(n);
    vector<int> disc(n);
    vector<bool> visited(n, false);
    map<pair<int, int>, bool> is_bridge;
    auto dfs_tarjan = [&](auto &&self, int node, int parent) -> void {
        visited[node] = true;
        disc[node] = low[node] = time++;
        for(auto &neigh : adj[node]){
            if(neigh == parent) continue;
            if(visited[neigh]){
                low[node] = min(low[node], disc[neigh]);
            }else{
                self(self, neigh, node);
                low[node] = min(low[node], low[neigh]);
                if(low[neigh] > disc[node]){
                    is_bridge[{node, neigh}] = true;
                }
            }
        }
    };

    int components = 0;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            components++;
            dfs_tarjan(dfs_tarjan, i, -1);
        }
    }

    for(auto &[edge, bridge] : is_bridge){
        cout << edge.first << ' ' << edge.second << ' ' << (bridge ? " is_bridge " : " not_brige ") << endl;
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