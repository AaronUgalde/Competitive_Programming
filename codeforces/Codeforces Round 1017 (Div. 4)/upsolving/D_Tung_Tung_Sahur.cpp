#include <bits/stdc++.h>
using namespace std;

void solve(int testcase){
    string p; cin >> p;
    string s; cin >> s;

    int n = p.size();
    int m = s.size();
    int i = 0, j = 0;

    while(i < n && j < m){
        if(p[i] != s[j]){
            cout << "NO" << '\n';
            return;
        }

        int cntP = 0, cntS = 0;
        while(i < n && p[i + cntP] == p[i]) cntP++;
        while(j < m && s[j + cntS] == s[j]) cntS++;

        if(cntS < cntP || cntS > 2 * cntP){
            cout << "NO" << '\n';
            return;
        }

        i += cntP;
        j += cntS;
    }

    cout << ((i == p.size() && j == s.size()) ? "YES\n" : "NO\n");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(t);
    }
}