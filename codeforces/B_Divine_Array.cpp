#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    // Mapeo de t, i -> int
    vector<vector<int>> t_state(n + 1, vector<int>(n, 0));
    //bucket
    vector<int> bucket(n + 1);
    for(auto &a : t_state[0]){
        cin >> a;
        bucket[a]++;
    }

    for(int t = 1; t <= n; t++){
        for(int i = 0; i < n; i++){
            t_state[t][i] = bucket[t_state[t - 1][i]];
        }
        bucket.assign(n + 1, 0);
        for(int i = 0; i < n; i++){
            bucket[t_state[t][i]]++;
        }
    }

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int j, t; 
        cin >> j >> t;
        j--;
        t = (t <= n ? t : n);
        
        cout << t_state[t][j] << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}