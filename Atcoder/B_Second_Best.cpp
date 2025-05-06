#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n; cin >> n;
    vector<pair<int, int>> A(n);
    for(int i = 0; i<n; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());

    cout << A[n - 2].second + 1 << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}