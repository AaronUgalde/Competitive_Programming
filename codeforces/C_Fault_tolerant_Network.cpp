#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<ll> A(n);
    vector<ll> B(n);
    for(auto &a : A) cin >> a;
    for(auto &b : B) cin >> b;

    auto min_pair = [&](ll x, vector<ll> &v){
        ll mn = LLONG_MAX;
        for(int i = 0; i<n; i++){
            mn = min(mn, abs(x - v[i]));
        }
        return mn;
    };

    ll min_a0 = min_pair(A[0], B);
    ll min_aN = min_pair(A[n-1], B);
    ll min_b0 = min_pair(B[0], A);
    ll min_bN = min_pair(B[n-1], A);

    ll ans1 = 0;
    ans1 += min(abs(A[0] - B[0]), min_a0 + min_b0);
    ans1 += min(abs(A[n-1] - B[n-1]), min_aN + min_bN);
    ll ans2 = 0;
    ans2 += min(abs(A[0] - B[n-1]), min_a0 + min_bN);
    ans2 += min(abs(A[n-1] - B[0]), min_aN + min_b0);

    cout << min(ans1, ans2) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}