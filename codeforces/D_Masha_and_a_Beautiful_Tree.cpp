#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int m; cin >> m;
    vector<int> P(m);
    for(auto &p : P) cin >> p;

    int ans = 0;
    while(m > 1){
        for(int i = 0; i<m; i+=2){
            if(P[i] % 2 == 0 && P[i+1] == P[i] - 1){
                P[(i+1)/2] = P[i]/2;
                ans++;
            }else if(P[i+1] % 2 == 0 && P[i] == P[i+1] - 1){
                P[(i+1)/2] = P[i+1]/2;
            }else{
                cout << -1 << endl;
                return;
            }
        }             
        m /= 2;
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}