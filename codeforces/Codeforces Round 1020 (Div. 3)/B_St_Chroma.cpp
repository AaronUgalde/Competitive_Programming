#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n, x; cin >> n >> x;
    int i = 0; 
    for(int j = 0; j < n - 1; j++){
        if(x == i){
            i++;
        }
        cout << i << ' ';
        i++;
    }

    if(x < n) cout << x << '\n';
    else cout << i << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}