#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n, m, k; cin >> n >> m >> k;
    vector<int> A(n), B(m);
    for(auto &a : A) cin >> a;
    for(auto &b : B) cin >> b;

    sort(all(A));
    sort(all(B));

    if(A[0] < B[m - 1]){
        swap(A[0], B[m - 1]);
        sort(all(A));
        sort(all(B));
    } 

    if(k == 1){
        cout << accumulate(all(A), 0ll) << endl;
        return;
    }

    if(B[0] < A[n - 1]){
        swap(B[0], A[n - 1]);
        sort(all(A));
        sort(all(B));
    }

    if(k % 2 == 0){
        cout << accumulate(all(A), 0ll) << endl;
        return;
    }

    swap(A[0], B[m - 1]);
    cout << accumulate(all(A), 0ll) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}