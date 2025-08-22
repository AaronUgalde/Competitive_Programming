#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int MAXN = 2e5;
int n;
vector<int> adj[MAXN];
vector<bool> vis(MAXN, false);

void dfs(int start){
    vis[start] = true;
    for(auto &neigh : adj[start]){
        if(!vis[neigh]) dfs(neigh);
    }
}

void solve(int testcase){
    int m; cin >> n >> m;
    for(int i = 0; i<m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);
    for(int i = 0; i<n; i++){
        if(adj[i].size() != 2 || !vis[i]){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}