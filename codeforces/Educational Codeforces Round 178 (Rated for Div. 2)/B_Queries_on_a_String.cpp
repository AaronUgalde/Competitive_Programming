#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(int testcase){
    string s; cin >> s;
    int q; cin >> q;
    for(int i = 0; i<q; i++){
        int l, r, k; cin >> l >> r >> k;
        int mod = r - l + 1;
        k %= mod;
        string shift = s;
        for(int j = 0; j<mod; j++){
            shift[(j+k)%mod + l - 1] = s[j + l - 1];
        }
        s = shift;
    }

    cout << s << endl; 
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}