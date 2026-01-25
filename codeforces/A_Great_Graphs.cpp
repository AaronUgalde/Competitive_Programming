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
    vector<ll> D(n);
    for(auto &d : D) cin >> d;
    sort(all(D), greater<int>());

    ll ans = D[0];
    ll a_i = accumulate(D.begin(), D.end(), 0ll);
    for(int i = 0; i < n; i++){
        a_i -= D[i];
        ans += a_i - (n - i - 1) * D[i];
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