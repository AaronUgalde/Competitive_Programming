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

    vector<ll> suf(n + 1);
    suf[n] = 0;
    ll ans = 0;
    for(int i = n - 1; i >= 1; i--){
        suf[i] = suf[i + 1] + A[i];
        if(suf[i] >= 0){
            ans += suf[i];
        }
    }

    cout << suf[1] + A[0] + ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}