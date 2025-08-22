#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<vector<ll>> arrays(n);
    int mn = INT_MAX;
    int idx_mn = 0;
    vector<ll> zero(n);
    vector<ll> one(n);
    for(int i = 0; i<n; i++){
        int m; cin >> m;
        arrays[i].resize(m);
        for(int j = 0; j<m; j++){
            cin >> arrays[i][j];
        }
        sort(all(arrays[i]));
        zero[i] = arrays[i][0];
        one[i] = arrays[i][1];
    }

    sort(all(zero));
    sort(all(one));
    ll sum = accumulate(all(one), 0LL) - one[0] + zero[0];
    cout << sum << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}