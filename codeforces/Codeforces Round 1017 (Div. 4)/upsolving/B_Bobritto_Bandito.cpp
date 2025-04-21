#include <bits/stdc++.h>
using namespace std;


void solve(int testcase){
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int d = n - m;
    int L = min(l+d, 0);
    d -= abs(L-l);
    int R = r - d;
    cout << L << " "  << R << '\n';
}

int main(){
    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(t);
    }
}