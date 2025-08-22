#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    string l, r; cin >> l >> r;
    int ans = 0;
    bool one = false;
    for(int i = 0; i<sz(l); i++){
        int diff = 0;
        if(one){
            diff = 10 - l[i] + r[i];
        }else{
            diff = abs(l[i] - r[i]);
        }
        
        if(diff == 1){
            one = true;
            ans += 1;
        }else if(diff == 0){
            ans += 2;
        }else{
            break;
        }
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