#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
    int find(int x) {
        return p[x]==x ? x : p[x]=find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a==b) return false;
        if (r[a]<r[b]) swap(a,b);
        p[b]=a;
        if (r[a]==r[b]) r[a]++;
        return true;
    }
};

// --- Estructura para almacenar aristas ---
struct Edge {
    int u, v;
    long long w;
    bool operator<(Edge const& other) const {
        return w < other.w;
    }
};

long long kruskal(int n, vector<Edge>& edges, vector<Edge>& mst) {
    sort(edges.begin(), edges.end());     // O(E log E)
    DSU dsu(n);
    long long total = 0;
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            total += e.w;
            mst.push_back(e);
            if ((int)mst.size() == n-1) break;
        }
    }
    return total;
}

class Solution {
    public:
        int minCostConnectPoints(vector<vector<int>>& points) {
            int n = points.size();
            vector<Edge> edges, mst;
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    edges.push_back({i, j, abs(points[i][1] - points[j][1]) + abs(points[i][0] - points[j][0])});
                }
            }

            int cost = kruskal(n, edges, mst);
            return cost;
        }
};

int main(){
    Solution sol;
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout << sol.minCostConnectPoints(points) << endl;
    return 0;
}