#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int dfs(int parent, int node, vector<vector<int>> &adj){
    if(adj[node].size() == 1 && parent != -1) return 1;
    int leaves = 0;
    for(auto &child : adj[node]){
        if(child != parent){
            leaves += dfs(node, child, adj);
        }
    }
    return leaves; 
}

void solve(int testcase){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i<n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int leaves = dfs(-1, 0, adj);
    if(adj[0].size() == 1){
        leaves++;
    }
    cout << (leaves+1)/2 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    cin >> t;

    for(int i = 0; i<t; i++){

        solve(i);
    }
}