#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    long long n; cin >> n; 
    map<long long, bool> sums;
    long long sum = 0; sums[0] = true;
    bool flag = false;
    for(int i = 0; i<n; i++){
        int glass; cin >> glass; 
        sum += (i % 2 == 0) ? glass : -glass;
        if(sums[sum]){
            flag = true;
        }else{
            sums[sum] = true;
        }
    }

    cout << (flag ? "YES\n" : "NO\n");
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}