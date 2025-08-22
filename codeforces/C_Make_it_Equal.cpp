#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n, k; cin >> n >> k;
    vector<int> S(n);
    vector<int> T(n);
    for(auto &s : S) cin >> s;
    for(auto &t : T) cin >> t;

    map<int, int> mod_k;
    for(auto &s : S){
        if(s == 0) s = k;
        mod_k[s % k]++;
    }

    for(auto &t : T){
        if(t == 0) t = k;
        if(mod_k[t % k] > 0) mod_k[t % k]--;
        else if(mod_k[abs((t % k) - k) % k] > 0) mod_k[abs((t % k) - k) % k]--;
        else{
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}