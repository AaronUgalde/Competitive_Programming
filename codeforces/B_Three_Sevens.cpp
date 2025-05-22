#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int m; cin >> m;
    vector<vector<int>> days(m);
    for(int i = 0; i<m; i++){
        int n; cin >> n;
        vector<int> day(n);
        for(int j = 0; j<n; j++){
            cin >> day[j];
        }
        days[i] = day;
    }

    const int MAXA = 5e4+1;
    vector<bool> appear(MAXA, false);
    vector<int> ans(m, -1);
    for(int i = m-1; i>=0; i--){
        for(int j = 0; j<days[i].size(); j++){
            if(!appear[days[i][j]]){
                ans[i] = days[i][j];
                appear[days[i][j]] = true;
            }
        }
        if(ans[i] == -1){
            cout << -1 << endl;
            return;
        }
    }

    for(int i = 0; i<m; i++){
        cout << ans[i] << ' ';
    }
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