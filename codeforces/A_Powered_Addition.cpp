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

    int max_diff = INT_MIN;
    for(int i = 1; i<n; i++){
        if(A[i] < A[i-1]){
            int diff = A[i-1] - A[i];
            max_diff = max(max_diff, diff);
            A[i] = A[i-1];
        }
    }

    if(max_diff == INT_MIN){
        cout << 0 << endl;
        return;
    }

    cout << 32 - __builtin_clz(max_diff) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}