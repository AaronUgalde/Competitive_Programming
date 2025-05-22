#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<vector<int>> dishes(m);
    for(int i = 0; i<m; i++){
        int k; cin >> k;
        for(int j = 0; j<k; j++){
            int a; cin >> a; a--;
            dishes[i].push_back(a);
        }    
    }

    vector<int> overcome(n);
    for(int i = 0; i<n; i++){
        int ing; cin >> ing; ing--;
        overcome[ing] = i;
    }

    vector<int> ans(n);
    for(int i = 0; i<m; i++){
        int mx = INT_MIN;
        for(int j = 0; j<dishes[i].size(); j++){
            mx = max(mx, overcome[dishes[i][j]]);
        }
        ans[mx]++;
    }

    int last = 0;
    for(int i = 0; i<n; i++){
        cout << last + ans[i] << endl;
        last += ans[i];
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