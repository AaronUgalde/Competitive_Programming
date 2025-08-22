#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    string s; cin >> s;

    int ans = 0;
    int idx_zero = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            if(idx_zero != i) ans += i + 1;
            idx_zero++;
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