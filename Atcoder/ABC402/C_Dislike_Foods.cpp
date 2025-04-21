#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<vector<bool>> foods(m);
    for(int i = 0; i<m; i++){
        int k; cin >> k;
        vector<bool> food(n+1, false);
        for(int j = 0; j < k; j++){
            int a; cin >> a;
            food[a] = true;
        }
        foods[i] = food;
    }

    vector<int> ponderation(n);
    for(int i = 0; i<n; i++){
        cin >> ponderation[i];
    }

    vector<int> ponderedFoods(m);
    for(int i = 0; i<m; i++){
        for(int j = n - 1; j >= 0; j--){
            if(foods[i][ponderation[j]]){
                ponderedFoods[i] = j;
                break;
            }
        }
    }


    vector<int> ans(n, 0);
    for(int i = 0; i<m; i++){
        ans[ponderedFoods[i]]++;
    }

    cout << ans[0] << '\n';
    for(int i = 1; i<n; i++){
        ans[i] += ans[i - 1];
        cout << ans[i] << '\n';
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