#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<int> costos(n);
    for(auto &costo : costos) cin >> costo;

    vector<int> p_3(n+1); p_3[0] = 1;
    for(int i = 1; i<=n; i++) p_3[i] = p_3[i-1] * 3;

    vector<int> zoos[n];
    for(int especie = 0; especie<m; especie++){
        int n_zoos; cin >> n_zoos;
        for(int i = 0; i<n_zoos; i++){
            int zoo; cin >> zoo; zoo--;
            zoos[zoo].push_back(especie);
        }
    }

    ll ans = LLONG_MAX;
    for(int mask = 0; mask < p_3[n]; mask++){
        vector<int> cnt(m, 0);
        ll res = 0;
        for(int zoo = 0; zoo < n; zoo++){
            int veces = (mask / p_3[zoo]) % 3;
            for(int v = 0; v<veces; v++){
                res += costos[zoo];
                for(int &especie : zoos[zoo]){
                    cnt[especie]++;
                }
            }
        }
        if(*min_element(all(cnt)) >= 2) ans = min(ans, res);
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