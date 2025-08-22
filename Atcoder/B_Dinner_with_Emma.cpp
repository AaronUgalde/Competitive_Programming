#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, m; cin >> n >> m;
    int max_min = INT_MIN;
    for(int i = 0; i<n; i++){
        int mn = INT_MAX;
        for(int j = 0; j<m; j++){
            int x; cin >> x;
            mn = min(mn, x);
        }
        max_min = max(max_min, mn);
    }

    cout << max_min << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}