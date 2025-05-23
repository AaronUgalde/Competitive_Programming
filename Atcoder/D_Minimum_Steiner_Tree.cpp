#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int MAXN = 2e5 + 5;
vector<ll> adj[MAXN];
ll sz[MAXN];

void dfs(int node, int parent){
    for(auto child : adj[node]){
        if(child == parent) continue;
        dfs(child, node);
        sz[node] += sz[child];
    }
}

void solve(int testcase){
    ll n, k; cin >> n >> k;
    for(ll i = 1; i < n; i++){
        ll u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll x;
    for(ll i = 0; i<k; i++){
        cin >> x;
        sz[x-1] = 1;
    }

    ll ans = 0;
    dfs(x-1, -1);
    for(int i = 0; i < n; i++){
        ans += (sz[i] > 0);
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