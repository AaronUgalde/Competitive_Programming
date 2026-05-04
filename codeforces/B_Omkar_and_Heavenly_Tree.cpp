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
    vector<int> restricted(n, false);
    
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c; b--;
        restricted[b] = true;
    }

    int root;
    for(int i = 0; i < n; i++){
        if(!restricted[i]){
            root = i;
            break;
        }
    }

    for(int i = 0; i < n; i++){
        if(i != root)
            cout << i + 1 << ' ' << root + 1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}