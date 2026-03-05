#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1){
            res = (res * a) % MOD;
        }
        b >>= 1;
        a = (a * a) % MOD;
    }
    return res;
}

void solve(int testcase){
    ll n, k; cin >> n >> k;
    vector<vector<ll>> adj(n);
    for(int i = 0; i < n - 1; i++){
        ll u, v, x; cin >> u >> v >> x;
        u--; v--;
        if(x == 1) continue;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }


    vector<bool> visited(n, false);
    auto dfs = [&](auto &&self, int u) -> ll{
        visited[u] = true;
        ll size = 1;
        for(auto &v : adj[u]){
            if(visited[v]) continue;
            size += self(self, v);
        }
        return size;
    };

    ll ans = binpow(n, k);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            ans = (ans % MOD - binpow(dfs(dfs, i), k) % MOD + MOD) % MOD;
        }
    }

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