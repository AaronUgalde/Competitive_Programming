#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, k; cin >> n >> k;
    vector<int> A(n), T(n);
    for(auto &a : A) cin >> a;
    for(auto &t : T) cin >> t;

    vector<int> A_c = A;
    for(int i = 0; i<n; i++){
        if(T[i] == 1) A_c[i] = 0;
    }

    vector<int> prefix(n+1);
    prefix[0] = 0;
    for(int i = 1; i<=n; i++){
        prefix[i] = prefix[i-1] + A_c[i-1];
    }
    cout << endl;

    int maxSum = prefix[k];
    for(int i = k+1; i<=n; i++){
        maxSum = max(maxSum, prefix[i] - prefix[i-k]);
    }

    for(int i = 0; i<n; i++){
        if(T[i] == 1) maxSum += A[i];
    }

    cout << maxSum << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}