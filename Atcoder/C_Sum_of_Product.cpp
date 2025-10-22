#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    ll n; cin >> n;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    vector<ll> prefix(n);
    prefix[0] = A[0];
    for(int i = 1; i < n; i++){
        prefix[i] += prefix[i - 1] + A[i];
    }

    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += 1ll * A[i] * (prefix[n - 1] - prefix[i]);
    }

    cout << sum << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}