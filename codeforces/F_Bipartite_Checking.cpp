#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 100000;
const int MAXQ = 100000;
vector<vector<bool>> adj(MAXN, vector<bool>(MAXN, false));

void solve(int testcase){
    int n, q; cin >> n >> q;
    for(int i = 0; i<q; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u][v] != adj[u][v];
    }

    vector<int> side(n, -1);
    bool is_bipartite = true;
    queue<int> qu;
    for (int st = 0; st < n; ++st) {
        if (side[st] == -1) {
            qu.push(st);
            side[st] = 0;
            while (!qu.empty()) {
                int v = qu.front();
                qu.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        qu.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }

    cout << (is_bipartite ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}