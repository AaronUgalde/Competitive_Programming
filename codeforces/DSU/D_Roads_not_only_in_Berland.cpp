#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n), r(n, 0) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;           
        if (r[a] < r[b]) swap(a, b);        
        p[b] = a;                           
        if (r[a] == r[b]) r[a]++;           
        return true;
    }
};

void solve(int testcase){
    int n; cin >> n;
    DSU dsu(n+1);
    vector<pair<int, int>> build, destroy;

    for(int i = 0; i<n; i++){
        int u, v; cin >> u >> v;
        if(dsu.find(u) == dsu.find(v)){
            destroy.emplace_back(u, v);
        }else{
            dsu.unite(u, v);
        }
    }

    for(int i = 2; i <= n; i++){
        if(dsu.find(1) != dsu.find(i)){
            dsu.unite(1, i);
            build.emplace_back(1, i);
        }
    }

    cout << build.size() << '\n';

    for(int i = 0; i<build.size(); i++){
        cout << destroy[i].first << " " << destroy[i].second << " " << build[i].first << " " << build[i].second << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}