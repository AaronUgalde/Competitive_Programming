#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;
    sort(all(A));

    ll g = 0;
    for(int i = 1; i < n; i++){
        if(A[i] % A[0] == 0) g = gcd(g, A[i]);
    }

    cout << (g == A[0] ? "Yes" : "No") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}