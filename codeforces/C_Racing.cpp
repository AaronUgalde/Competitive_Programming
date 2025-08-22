#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> d(n);
    for(auto &x : d) cin >> x;
    vector<pair<int, int>> obstacles(n);
    for(auto &[l, r] : obstacles) cin >> l >> r;

    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(d[i] == 1){
            cnt++;
        }
        obstacles[i].first -= cnt;
        obstacles[i].second -= cnt;
    }

    int mx = 0;
    int up = 0;
    for(auto &[l, r] : obstacles){
        if(l > mx){
            up += l - mx;
            mx = l;
        }
    }

    for(int i = n-2; i >= 0; i--){
        auto &[l, r] = obstacles[i];
        auto &[l_1, r_1] = obstacles[i+1];
        r = min(r, r_1);
    }

    int h = 0;
    for(int i = 0; i<n; i++){
        auto &[l, r] = obstacles[i];
        if(d[i] == -1){
            if(up){
                if(h+1 <= r){
                    h++;
                    up--;
                    d[i] = 1;
                }else{
                    d[i] = 0;
                }
            }else{
                d[i] = 0;
            }
        }
        if(h < l || h > r){
            cout << -1 << endl;
            return;
        }
    }

    for(auto &x : d) cout << x << ' ';
    cout << endl;
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}