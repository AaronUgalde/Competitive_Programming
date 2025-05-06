#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;
    bool aOne = s[0] == 'A', aN = s[n - 1] == 'A', aNMinus = s[n - 2] == 'A';
    int bobC = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'B') bobC++;
    }

    if(bobC == 1 && !aN){
        cout << "Alice" << '\n';
        return;
    }

    cout << (aN && (aOne || aNMinus) ? "Alice\n" : "Bob\n");
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}