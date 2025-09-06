#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

struct node{
    int w;
    int d;
};

bool cmp_nodes(const node &a, const node &b){
    return a.w > b.w;
}

void solve(int testcase){
    int n; cin >> n;
    vector<node> nodes(n);
    ll total = 0;
    for(auto &n : nodes) cin >> n.w, total += n.w;

    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        nodes[u].d++;
        nodes[v].d++;
    }

    sort(all(nodes), cmp_nodes);

    for(int i = 0, k = 0, j = 0; i < n - 1; i++){
        while(j > 0 && k < n){
            if(nodes[k].d >= 2){
                while(nodes[k].d >= 2 && j > 0){
                    total += nodes[k].w;
                    nodes[k].d--;
                    j--;
                    //cout << "i: " << i << " j: "  << j << " k: " << k << " total: " << total << " d; " << nodes[k].d << endl;
                }
            }
            if(nodes[k].d == 1) k++;
        }
        j++;
        cout << total << ' ';
    }

    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}