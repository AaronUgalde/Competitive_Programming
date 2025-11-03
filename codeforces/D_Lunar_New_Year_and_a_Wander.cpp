#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set<int> neigh = {0};
    vector<bool> visited(n);
    vector<int> ans;
    auto dfs = [&](auto &&self, int start) -> void{
        neigh.erase(start);
        visited[start] = true;
        ans.push_back(start);
        for(auto &n : adj[start]){
            if(!visited[n]){
                neigh.insert(n);
            }
        }
        if(!neigh.empty()) self(self, *neigh.begin());
    };

    dfs(dfs, 0);
    for(auto &a : ans) cout << a + 1 << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}