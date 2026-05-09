#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parity(2);

    auto dfs = [&](auto &&self, int u, int parent, int mod2) -> void{
        parity[mod2]++;
        for(auto &v : adj[u]){
            if(v != parent){
                self(self, v, u, (mod2 + 1) % 2);
            }
        }
    };

    dfs(dfs, 0, -1, 0);
    cout << 1ll * parity[0] * parity[1] - (n - 1) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}