#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n; cin >> n;
    bool ans = true, consecutive = false, isOne = false;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    sort(A.begin(), A.end());

    for(int i = 0; i<n; i++){
        if(i + 1 < n && A[i] == A[i + 1] - 1) consecutive = true;
        if(A[i] == 1) isOne = true;
    }

    if(isOne && consecutive) ans = false;

    cout << (ans ? "YES\n" : "NO\n");
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}