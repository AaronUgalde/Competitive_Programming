#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n, m; cin >> n >> m;

    vector<int> parent(n);
    vector<ll> size(n, 1);
    iota(all(parent), 0);

    auto find_set = [&](auto &&self, int v) -> int{
        if(parent[v] == v)
            return v;
        return parent[v] = self(self, parent[v]);
    };

    auto union_sets = [&](int u, int v){
        int a = find_set(find_set, u);
        int b = find_set(find_set, v);
        if(a == b) return;
        if(size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    };

    for(int i = 0; i < m; i++){
        int size_group; cin >> size_group;
        vector<int> group(size_group);
        for(auto &a : group) cin >> a, a--;
        for(int j = 0; j < size_group - 1; j++){
            union_sets(group[j], group[j + 1]);
        }
    }

    for(int i = 0; i < n; i++){
        cout << size[find_set(find_set, i)] << ' ';
    }

    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}