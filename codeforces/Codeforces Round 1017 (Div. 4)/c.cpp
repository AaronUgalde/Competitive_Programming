#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for(int i = 0; i<t; i++){
        int n; cin >> n;
        vector<int> ans(2*n);
        vector<bool> vis(2*n, false);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int g; cin >> g;
                vis[g] = true;
                ans[i +  j + 1] = g;
            }
        }

        for(int i = 1; i<=2*n; i++){
            if(!vis[i]){
                ans[0] = i;
            }
        }

        for(int i = 0; i<2*n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}