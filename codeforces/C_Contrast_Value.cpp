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

    n = unique(all(A)) - A.begin();
    int ans = n;
    for(int i = 0; i + 2 < n; i++){
        ans -= (A[i] < A[i+1] && A[i+1] < A[i+2]);
        ans -= (A[i] > A[i+1] && A[i+1] > A[i+2]);
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}