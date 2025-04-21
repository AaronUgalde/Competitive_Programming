#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    string s; cin >> s;
    for(int i = 0; i<s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            cout << s[i];
        }
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