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
    map<int, int> mp;
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--; v--;
        mp[u]++;
        mp[v]++;
    }

    bool more_than_two = false;
    for(auto &[u, cnt] : mp){
        if(cnt > 2 and more_than_two == false){
            more_than_two = true;
        }else if(cnt > 2 and more_than_two == true){
            cout << "No" << endl;
            return;
        }
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