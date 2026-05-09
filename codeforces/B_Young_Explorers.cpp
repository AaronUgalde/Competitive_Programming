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
    vector<int> E(n);
    for(auto &e : E) cin >> e;

    sort(all(E));
    int current_size = 0;
    int need_size = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        need_size = E[i];
        current_size++;
        if(current_size >= need_size){
            ans++;
            current_size = 0;
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}