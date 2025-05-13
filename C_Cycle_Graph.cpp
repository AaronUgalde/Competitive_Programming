#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int

vector<int> adj[]

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i<m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        if(adj[u] != -1 || adj[v] != -1){
            cout << "No" << endl;
            return;
        }
        adj[u] = v;
        adj[v] = u;
    }

    int actual = 0;
    vector<bool> vis(n, false);
    for(int i = 0; i<n; i++){
        vis[actual] = true;
        actual = adj[actual];
    }

    if(actual != 0){
        cout << "No" << endl;
        return;
    }

    for(int i = 0; i<n; i++){
        if(vis[i] != true){
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