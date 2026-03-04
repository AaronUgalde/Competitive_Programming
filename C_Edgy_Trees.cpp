#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

const ll MOD = 1e9 + 7;

void solve(int testcase){
    int n, k; cin >> n >> k;
    vector<vector<pair<int, int>>> adj(n);
    int start = -1;
    for(int i = 0; i < n - 1; i++){
        int u, v, x; cin >> u >> v >> x;
        u--; v--;
        adj[u].emplace_back(v, x);
        adj[v].emplace_back(u, x);
        if(x == 1) start = u;
    }

    if(start == -1){
        cout << 0 << endl;
        return;
    }

    vector<int> size_group(n, 0);
    vector<int> visited(n, false);
    int group = 0;
    auto dfs = [&](auto &&self, int parent_group, int u) -> void{
        visited[u] = true;
        int my_group = group;
        if(parent_group == -1) size_group[group]++;
        else size_group[parent_group]++;
        for(auto &[v, color] : adj[u]){
            if(visited[v]) continue;
            if(color == 0){
                self(self, my_group, v);
            }else{
                group++;
                self(self, -1, v);
            }
        }
    };

    dfs(dfs, -1, start);

    ll valid_moves = 0;
    for(auto &x : size_group){
        valid_moves += 1ll * (n - x) * x % MOD;
    }
    ll ans = 1;
    for(int i = 0; i < n - 2; i++){
        ans = 1ll * (ans * n) % MOD;
    }
    ans = 1ll * (ans * valid_moves) % MOD;
    ans = 1ll * (ans * k) % MOD;

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}