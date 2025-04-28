#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    string s, t; cin >> s >> t;
    int i = s.size() - 1;
    int j = t.size() - 1;
    while(j >= 0 && i >= 0){
        if(s[i] == t[j]){
            i--; j--;
        }else{
            i -= 2;
        }
    }
    cout << (j != -1 ? "NO\n" : "YES\n");
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}