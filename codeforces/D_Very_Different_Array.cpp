#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<ll> A(n), B(m);
    for(auto &a : A) cin >> a;
    for(auto &b : B) cin >> b;
    
    sort(all(A));
    sort(all(B), greater<ll>());

    ll ans = 0, res = 0;
    for(int i = 0; i < n; i++){
        res += abs(A[i] - B[i]);
    }
    ans = res;

    for(int i = 1; i <= n; i++){
        res = res - abs(A[n - i] - B[n - i]) + abs(A[n - i] - B[m - i]);
        ans = max(ans, res);
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