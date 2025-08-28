#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

vector<ll> tree;
ll query(int node, int l, int h, int q_l, int q_h){
    if(l >= q_l && h <= q_h){
        //cout << "node: " << node << " q_l: " << q_l << " q_h: " << q_h << " tree[node]: " << tree[node] << endl; 
        return tree[node];
    }
    if(h < q_l || l > q_h){
        return INT_MAX;
    }
    return min(query(2 * node, l, (l + h) / 2, q_l, q_h)
        , query(2 * node + 1, (l + h) / 2 + 1, h, q_l, q_h));
}

void solve(int testcase){
    int n, q; cin >> n >> q;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    n = 1;
    while(n < (int)sz(A)) n <<= 1;

    tree.resize(2 * n);
    for(int i = 0; i < sz(A); i++){
        tree[n + i] = A[i];
    }
    for(int i = n - 1; i >= 1; i--){
        tree[i] = min(tree[2 * i] , tree[2 * i + 1]);
    }

    for(int i = 0; i<q; i++){
        int a, b; 
        cin >> a >> b;
        a--; b--;
        cout << query(1, 0, n - 1, a, b) << endl;
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