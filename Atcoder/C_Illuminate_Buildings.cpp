#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n; cin >> n;
    vector<int> H(n);
    for(auto &h : H) cin >> h;

    int min_i = 1;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            int k;
            for(k = j*2; k < n; k += i){
                if(H[k] != H[k - i]){
                    break;
                }
            }
            if(k >= n){
                min_i = i;
                break;
            }
        }
    }

    cout << n/min_i << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}