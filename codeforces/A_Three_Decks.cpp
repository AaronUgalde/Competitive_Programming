#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int a, b, c; cin >> a >> b >> c;
    c -= b - a;
    if(c >= b)
        cout << ((c - b) % 3 == 0 ? "YES\n" : "NO\n");
    else
        cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}