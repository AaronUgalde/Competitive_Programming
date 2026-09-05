#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

struct DSU{
    vector<int> parent;
    vector<int> size;
    int components;
    DSU(size_t n) : parent(n), size(n, 1), components(n){
        iota(all(parent), 0);
    }

    int find(int v){
        if(v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void unite(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu != pv){
            if(size[pu] < size[pv]){
                swap(pu, pv);
            }
            parent[pv] = pu;
            size[pu] += size[pv]; 
            components--;
        }
    }
};

void solve(){
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<int, int>> eF(m1);
    DSU dsuF(n), dsuG(n);
    for(int i = 0; i < m1; i++){
        int u, v; cin >> u >> v; u--; v--;
        eF[i] = {u, v};
    }
    for(int i = 0; i < m2; i++){
        int u, v; cin >> u >> v; u--; v--;
        dsuG.unite(u, v);
    }

    int ans = 0;
    for(auto [u, v] : eF){
        if(dsuG.find(u) != dsuG.find(v)){
            ans++;
        }else{
            dsuF.unite(u, v);
        }
    }

    cout << ans + (dsuF.components - dsuG.components) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}