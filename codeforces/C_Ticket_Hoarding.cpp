#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    sort(all(A));
    ll ans = 0;
    for(int i = 0; i < n and k > 0; i++){
        int new_k = max(0, k - m);
        int bought = k - new_k;
        ans += 1ll * A[i] * bought;
        ans += 1ll * bought * new_k;
        k = new_k;
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}