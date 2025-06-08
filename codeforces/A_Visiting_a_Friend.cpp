#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> tps(n);
    for(auto &[a, b] : tps) cin >> a >> b;

    sort(all(tps));
    int min_a = 0, max_b = 0;
    for(auto &[a, b] : tps){
        if(a <= max_b){
            max_b = max(b, max_b);
        }
    }

    cout << (m <= max_b ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}