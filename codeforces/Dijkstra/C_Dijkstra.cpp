#include <bits/stdc++.h>
using namespace std;
#define ll long long


const ll INF = LLONG_MAX;

vector<vector<pair<int, ll>>> adj;
vector<ll> dist;
vector<int> parent;

void dijkstra(int s) {
    int n = adj.size();
    
    dist.assign(n, INF);
    parent.assign(n, -1);

    dist[s] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            ll nd = d + w;
            
            if (nd < dist[v]) {
                dist[v] = nd;      
                parent[v] = u;     
                pq.push({nd, v});  
            }
        }
    }
}

void solve(int testcase){
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}