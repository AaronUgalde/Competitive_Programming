#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n; cin >> n;
    vector<int> P(n);
    for(auto &p : P) cin >> p;

    vector<int> kid_id(n, -1);
    vector<int> id_size(n, 0);
    int id = 0;
    for(int i = 0; i < n; i++){
        if(kid_id[i] != -1) continue;
        int size = 0;
        int j = i;
        while(kid_id[j] == -1){
            size++;
            kid_id[j] = id;
            j = P[j] - 1;
        }
        id_size[id] = size;
        id++;
    }

    for(int i = 0; i < n; i++){
        cout << id_size[kid_id[i]] << ' ';
    }

    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}