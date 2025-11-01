#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, k; cin >> n >> k;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    ll sum = 0;
    for(int i = 0; i < n - 1; i++){
        if(A[i] + A[i + 1] < k){
            sum += k - (A[i] + A[i + 1]);
            A[i + 1] += k - (A[i] + A[i + 1]);
        }
    }

    cout << sum << endl;
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