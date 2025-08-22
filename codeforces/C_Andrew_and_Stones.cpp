#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    ll odds = 0; 
    for(auto &a : A){
        cin >> a;
        if(a % 2 != 0) odds++;
    }

    odds -= (A[0] % 2 != 0) + (A[n-1] % 2 != 0);

    if((odds == 1 && n == 3) || (accumulate(all(A), 0ll) - A[0] - A[n-1]) == n - 2){
        cout << -1 << endl;
        return;
    }

    cout << (accumulate(all(A), 0ll) - odds - A[0] - A[n-1]) / 2 + odds << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}