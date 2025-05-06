#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n; cin >> n;
    int k = 1;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            k = i;
            break;
        }
    }

    if(k == 1){
        k = n;
    }

    cout << n/k << ' ' << n - (n/k) << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}