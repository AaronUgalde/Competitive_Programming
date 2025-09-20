#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    int sum = 0;
    vector<int> x(n + 1);
    x[n] = INT_MAX; 
    for(int i = n - 1; i >= 0; i--){
        if(A[i] < x[i + 1]) x[i] = A[i];
        else x[i] = x[i + 1] - 1;
        x[i] = max(x[i], 0);
    }

    x[n] = 0;

    cout << accumulate(all(x), 0ll) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}