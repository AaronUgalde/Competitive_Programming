#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    ll n; cin >> n;
    int operations = 0;
    while(n % 2 == 0){
        n /= 2;
        operations++;
    }

    while(n % 3 == 0){
        n /= 3;
        operations += 2;
    }

    while(n % 5 == 0){
        n /= 5;
        operations += 3;
    }

    cout << (n == 1 ? operations : -1) << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}