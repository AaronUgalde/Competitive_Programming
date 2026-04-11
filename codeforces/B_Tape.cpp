#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> B(n);
    for(auto &b : B) cin >> b;

    vector<ll> diff(n - 1);
    for(int i = 1; i < n; i++){
        diff[i - 1] = B[i] - B[i - 1] - 1;
    }

    ll total = B[n - 1] - B[0] + 1;
    sort(all(diff), greater<int>());
    cout << total - accumulate(diff.begin(), diff.begin() + k - 1, 0ll) << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}