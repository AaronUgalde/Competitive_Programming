#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    int time = 0;
    vector<int> low(n);
    vector<int> disc(n);
    vector<bool> visited_tarjan(n, false);
    vector<int> is_bridge(m);
    auto dfs_tarjan = [&](auto &&self, int node, int parent) -> void {
        visited_tarjan[node] = true;
        disc[node] = low[node] = time++;
        for(auto &neigh : adj[node]){
            if(neigh.first == parent) continue;
            if(visited_tarjan[neigh.first]){
                low[node] = min(low[node], disc[neigh.first]);
            }else{
                self(self, neigh.first, node);
                low[node] = min(low[node], low[neigh.first]);
                if(low[neigh.first] > disc[node]){
                    is_bridge[neigh.second] = true;
                }
            }
        }
    };

    auto dfs = [&](auto &&self, int node, vector<bool> &visited) -> pair<int, int>{
        int max_dist = 0;
        int max_node = node;
        visited[node] = true;
        for(auto &v : adj[node]){
            if(visited[v.first]) continue;
            auto [max_v, dist] = self(self, v.first, visited);
            int bridge = (is_bridge[v.second]);
            if(dist + bridge > max_dist){
                max_node = max_v;
                max_dist = dist + bridge;
            }
        }
        return {max_node, max_dist};
    };

    int components = 0;
    vector<bool> visited_1(n, false);
    vector<bool> visited_2(n, false);
    int paths = 0;
    for(int i = 0; i<n; i++){
        if(!visited_tarjan[i]){
            components++;
            dfs_tarjan(dfs_tarjan, i, -1);
            auto [leaf, dist] = dfs(dfs, i, visited_1);
            auto [leaf_2, max_dist] = dfs(dfs, leaf, visited_2);
            paths += max_dist;
        }
    }

    cout << paths + components - 1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}