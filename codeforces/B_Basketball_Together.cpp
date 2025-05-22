#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    int d; cin >> d;
    vector<int> players(n);
    for(auto &p : players) cin >> p;

    sort(all(players), greater<int>());
    int i_max = 0, total_picked = 1, n_picked = 1;
    int ans = 0;
    while(total_picked <= n){
        if(players[i_max] * n_picked > d){
            ans++;
            i_max++;
            total_picked++;
            n_picked = 1;
        }else{
            n_picked++;
            total_picked++;
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}