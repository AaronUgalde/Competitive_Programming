#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v; 
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n);
    auto dfs = [&](auto &&self, int u) -> bool {
        visited[u] = true;
        bool flag = true;
        for(auto &v : adj[u]){
            if(visited[v]) continue;
            flag = self(self, v);
        }
        return (sz(adj[u]) == 2 and flag);
    };

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        ans += dfs(dfs, i);
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}