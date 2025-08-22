#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, k; cin >> n >>k;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    sort(all(A));
    if(A[0] + 2*k < A[n-1]){
        cout << -1 << endl;
        return;
    }

    cout << A[0] + k << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}