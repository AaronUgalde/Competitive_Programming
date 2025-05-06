#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n; cin >> n;
    vector<vector<vector<ll>>> prefix(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0)));
    for(int x = 1; x<=n; x++){
        for(int y = 1; y<=n; y++){
            for(int z = 1; z<=n; z++){
                cin >> prefix[x][y][z];
                prefix[x][y][z] += prefix[x - 1][y][z] + prefix[x][y-1][z] + prefix[x][y][z-1] - prefix[x-1][y-1][z] - prefix[x][y-1][z-1] - prefix[x-1][y][z-1] + prefix[x-1][y-1][z-1];
            }
        }
    }

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int x1, x2, y1, y2, z1, z2; cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        x1--; y1--; z1--;
        ll ans = prefix[x2][y2][z2];
        ans -= prefix[x2][y2][z1 ] + prefix[x2][y1 ][z2] + prefix[x1 ][y2][z2];
        ans += prefix[x2][y1 ][z1 ] + prefix[x1 ][y1 ][z2] + prefix[x1 ][y2][z1 ];
        ans -= prefix[x1 ][y1 ][z1 ];
        cout << ans << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}