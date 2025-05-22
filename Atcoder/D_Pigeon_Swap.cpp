#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void printvec(vector<int> &v){
    for(int i = 0; i<v.size(); i++){
        cout << i << ':' << v[i] << ' ';
    }
    cout << endl;
}

void solve(int testcase){
    int n; cin >> n;
    vector<int> birds(n), id_nests(n), nests_id(n);
    iota(all(birds), 0);
    iota(all(id_nests), 0);
    iota(all(nests_id), 0);

    int q; cin >> q;
    for(int i = 0; i<q; i++){
        int t; cin >> t;
        if(t == 1){
            int a, b; cin >> a >> b; a--; b--;
            birds[a] = id_nests[b];
        }else if(t == 2){
            int a, b; cin >> a >> b; a--; b--;
            swap(nests_id[id_nests[a]], nests_id[id_nests[b]]);
            swap(id_nests[a], id_nests[b]);
        }else if(t == 3){
            int a; cin >> a; a--;
            cout << nests_id[birds[a]] + 1 << endl;
        }
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