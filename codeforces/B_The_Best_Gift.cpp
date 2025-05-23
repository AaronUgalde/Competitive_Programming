#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<int> genres(m);
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        genres[x-1]++;
    }

    ll ans = 0;
    for(int i = 0; i<m; i++){
        for(int j = i+1; j<m; j++){
            ans += (ll)genres[i] * genres[j];
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