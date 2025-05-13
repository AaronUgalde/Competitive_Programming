#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    map<int, int> pos;
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        pos[x] = i;
    }

    int n_0 = 0, n_1 = 0;
    vector<int> ans(n+1);
    for(int i = 1; i<=n; i++){
        if(pos[i]%2 == 0){
            ans[n_0*2] = i;
            n_0++;
        }else{
            ans[n_1*2+1] = i;
            n_1++;
        }
    }
    
    if(pos[n-2] == n-1 && pos[n-3] != n - 2){
        swap(ans[n-3], ans[n-1]);
    }

    for(int i = 0; i<n; i++){
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