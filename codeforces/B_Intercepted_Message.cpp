#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<int> X(n), Y(m);
    for(auto &x : X) cin >> x;
    for(auto &y : Y) cin >> y;

    int ans = 0;
    int i = 0, j = 0;
    int sum_X = X[0], sum_Y = Y[0];
    while(i < n && j < m){
        if(sum_X == sum_Y){
            ans++;
            i++;
            j++;
            sum_X = X[i];
            sum_Y = Y[j];
        }else if(sum_X < sum_Y){
            i++;
            sum_X += X[i];
        }else if(sum_X > sum_Y){
            j++;
            sum_Y += Y[j];
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