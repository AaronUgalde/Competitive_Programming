#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define sz(x) int((x).size())

vector<ll> tree, lazy;

void apply(int node, int l, int h, ll v){
    lazy[node] += v;
    tree[node] += v * ll(h - l + 1);
}

void push(int node, int l, int h){
    if(l == h || lazy[node] == 0) return;
    int m = (l + h) >> 1;
    apply(node * 2, l, m, lazy[node]);
    apply(node * 2 + 1, m+1, h, lazy[node]);
    lazy[node] = 0;
}

ll query(int node, int l, int h, int q_l, int q_h){
    if(h < q_l || l > q_h) return 0;           // no overlap
    if(q_l <= l && h <= q_h) return tree[node]; // full cover
    push(node, l, h);
    int m = (l + h) >> 1;
    return query(node * 2, l, m, q_l, q_h)
         + query(node * 2 + 1, m+1, h, q_l, q_h);
}

void update(int node, int l, int h, int q_l, int q_h, ll v){
    if(h < q_l || l > q_h) return;             // no overlap
    if(q_l <= l && h <= q_h){
        apply(node, l, h, v);
        return;
    }
    push(node, l, h);
    int m = (l + h) >> 1;
    update(node * 2, l, m, q_l, q_h, v);
    update(node * 2 + 1, m+1, h, q_l, q_h, v);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}

void solve(int testcase){
    int n_input, q; 
    if(!(cin >> n_input >> q)) return;
    vector<ll> A(n_input);
    for(auto &a : A) cin >> a;

    int n = 1;
    while(n < (int)A.size()) n <<= 1;

    tree.assign(2 * n, 0LL);
    lazy.assign(2 * n, 0LL);

    for(int i = 0; i < sz(A); i++){
        tree[n + i] = A[i];
    }
    for(int i = n - 1; i >= 1; i--){
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    for(int i = 0; i < q; ++i){
        int type; cin >> type;
        if(type == 1){
            int a, b; ll v;
            cin >> a >> b >> v;
            a--; b--;
            if(a > b) swap(a, b);
            if(a < 0) a = 0;
            if(b >= n) b = n-1;
            if(a <= b) update(1, 0, n - 1, a, b, v);
        } else {
            int a; cin >> a;
            a--;
            if(a < 0) a = 0;
            if(a >= n) a = n-1;
            cout << query(1, 0, n - 1, a, a) << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for(int tc = 0; tc < t; ++tc) solve(tc);
    return 0;
}
