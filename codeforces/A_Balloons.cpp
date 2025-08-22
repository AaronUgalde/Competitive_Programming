#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    if(n == 1){
        cout << -1 << endl;
        return;
    }

    int sum = accumulate(all(A), 0);
    for(int i = 0; i<n; i++){
        if(A[i] != (sum-A[i])){
            cout << 1 << endl;
            cout << i+1 << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}