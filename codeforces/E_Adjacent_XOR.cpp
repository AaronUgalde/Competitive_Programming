#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n), B(n);
    for(auto &a : A) cin >> a;
    for(auto &b : B) cin >> b;

    if(B[n - 1] != A[n - 1]){
        cout << "NO" << endl;
        return;
    }


    for(int i = 0; i < n - 1; i++){
        if(A[i] != B[i] && (A[i] ^ A[i + 1]) != B[i] && (A[i] ^ B[i+1]) != B[i]){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}