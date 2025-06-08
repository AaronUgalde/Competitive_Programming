#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s; 
    vector<int> mag(n);
    for(auto &b : mag) cin >> b; 

    bool zero = false;
    for(int i = 0; i<n; i++){
        if(s[i] == '0') zero = true;
        else if(s[i] == '1' && zero){
            s[i-1] = '1';
            int mn = min(mag[i-1], mag[i]);
            int mn_i = (mag[i-1] < mag[i] ? i-1 : i);
            int j = i + 1;
            for(; j<n && s[j] != '0'; j++){
                if(mag[j] < mn){
                    mn = mag[j];
                    mn_i = j;
                }
            }
            s[mn_i] = '0';
            i = j;
        }
    }

    int ans = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '1') ans+=mag[i];
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}