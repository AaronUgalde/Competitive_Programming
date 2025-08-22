#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

const ll MOD = 1e9 + 7;

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n), B(n);
    for(auto &a : A) cin >> a;
    for(auto &b : B) cin >> b;

    sort(all(A), greater<int>());
    sort(all(B), greater<int>());

    int j = 0;
    ll ways = 1;
    for(int i = 0; i<n; i++){
        while( j < n && A[j] > B[i]){
            j++;
        }
        ways = (ways * (j - i)) % MOD;
    }

    cout << ways << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}