#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    for(int i = 1; i < n - 1; i++){
        A[i] -= 2 * A[i - 1];
        A[i + 1] -= A[i - 1];
        if(A[i] < 0 || A[i + 1] < 0){
            cout << "NO" << endl;
            return;
        }
    }

    if(A[n - 1] != 0 || A[n - 2] != 0){
        cout << "NO" << endl;
        return;
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