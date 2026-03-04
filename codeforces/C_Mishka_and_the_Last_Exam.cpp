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
    vector<ll> B(n / 2);
    for(auto &b : B) cin >> b;

    vector<ll> A(n);
    ll l = 0, r = LLONG_MAX;
    for(int i = 0; i < n / 2; i++){
        if(B[i] - l > r){
            l += (B[i] - l) - r;
        }else{
            r = B[i] - l;
        }
        A[i] = l;
        A[n - i - 1] = r;
    }

    for(auto &a : A) cout << a << ' ';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}