#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(2*n);
    for(auto &a : A) cin >> a;
    
    sort(all(A));

    if(A[0] == A[2*n - 1]){
        cout << -1 << endl;
        return;
    }

    for(auto &a : A) cout << a << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}