#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return x >= 2;
}

void solve(int testcase){
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        ll x; cin >> x;
        ll y = sqrt(x);
        cout << (y * y == x ? (isPrime(y) ? "YES\n" : "NO\n") : "NO\n"); 
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