#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    map<int, int> node_edges;
    vector<vector<int>> adj(n);
    for(int i = 0; i<n-1; i++){
        int u, v; cin >> u >> v; 
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        node_edges[u]++;
        node_edges[v]++;
    }

    map<int, int> roots;
    int sum = 0;
    for(auto &[node, edges] : node_edges){
        if(edges == 1){
            roots[adj[node][0]]++;
            sum++;
            //cout << adj[node][0] << ' ';
        }
    }

    int max_node = 0;
    int max_root;
    for(auto &[root, leafs] : roots){
        if(leafs >= max_node){
            max_node = leafs;
            max_root = root;
        }
    }

    if(node_edges[max_root] == 1){
        cout << '0' << endl;
        return;
    }

    cout << sum - max_node << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}