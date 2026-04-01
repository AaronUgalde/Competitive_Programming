#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n, k; cin >> n >> k;
    vector<string> plane(n);
    for(auto &s : plane) cin >> s;

    int ans = 0;
    vector<pair<int, pair<int, int>>> free_sits;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 12; j++){
            if(plane[i][j] == 'P' or plane[i][j] == '-') continue;
            if(plane[i][j] == 'S'){
                if(j - 1 >= 0 and (plane[i][j - 1] == 'P' or plane[i][j - 1] == 'S')) ans++;
                if(j + 1 < 12 and (plane[i][j + 1] == 'P' or plane[i][j + 1] == 'S')) ans++;
            }else if(plane[i][j] == '.'){
                int status = 0;
                if(j - 1 >= 0 and plane[i][j - 1] == 'S') status++;
                if(j + 1 >= 0 and plane[i][j + 1] == 'S') status++;
                free_sits.push_back({status, {i, j}});
            }
        }
    }

    sort(all(free_sits));

    for(int i = 0; i < k; i++){
        ans += free_sits[i].first;
        plane[free_sits[i].second.first][free_sits[i].second.second] = 'x';
    }

    cout << ans << endl;
    for(auto &s : plane){
        for(auto &c : s){
            cout << c;
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}