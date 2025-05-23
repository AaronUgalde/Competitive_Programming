#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int cnt = 0;
const int MAXN = 2e5;
vector<int> adj[MAXN];
vector<bool> vis(MAXN, false);

void dfs(int start, int parent){
    vis[start] = true;
    for(auto &node : adj[start]){
        if(vis[node] && node != parent) cnt++;
        if(!vis[node] && node != parent) dfs(node, start);
    }
}

void solve(int testcase){
    int n, m; cin >> n >> m;
    for(int i = 0; i<m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i<n; i++){
        if(!vis[i]) dfs(i, -1);
    }

    cout << cnt/2 << endl; 
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}