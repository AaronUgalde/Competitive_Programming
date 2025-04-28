#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    ll ans = 0;
    for(int i = 29; i >= 0; i--){
        ll cnt = 0;
        for(int j = 0; j < n; j++){
            if(A[j] >= (1 << i) && A[j] < (1 << (i + 1))) cnt++;
        }
        ans += cnt*(cnt - 1)/2;
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}