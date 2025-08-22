#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n, m, q; cin >> n >> m >> q;
    vector<int> B(m);
    for(auto &b : B) cin >> b;

    sort(all(B));

    for(int i = 0; i<q; i++){
        int k; cin >> k;    
        int l = -1, r = m;
        while(r - l > 1){
            int m = l + (r - l) / 2;
            if(k < B[m]){
                r = m;
            }else{
                l = m;
            }
        }
        if(l == -1) cout << B[r] - 1 << endl;
        else if(r == m) cout << n - B[l] << endl;
        else{
            int k_l = abs(k - B[l]);
            int k_r = abs(k - B[r]);
            cout << (max(k_l, k_r)  - min(k_r, k_l))/2 + min(k_l, k_r) << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}