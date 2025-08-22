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

    if(n == 1){
        cout << 0 << endl;
        return;
    }

    int mn = *min_element(A.begin(), A.end()-1);
    int mx = *max_element(A.begin()+1, A.end());
    int t = INT_MIN;
    for(int i = 0; i<n; i++){
        t = max(t, A[(i+n-1)%n] - A[i]);
    }

    cout << max(t, max(A[n-1] - mn, mx - A[0])) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}