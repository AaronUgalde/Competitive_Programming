#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    ll h, w; cin >> h >> w;
    vector<vector<ll>> points(4);
    vector<ll> triangles(4);
    for(int i = 0; i<4; i++){
        int k; cin >> k;
        auto &s = points[i];
        s.resize(k);
        for(auto &p : s) cin >> p;
        triangles[i] = (s[k-1] - s[0]) * (i < 2 ? w : h);
    }


    cout << *max_element(all(triangles)) << endl;
}   

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}