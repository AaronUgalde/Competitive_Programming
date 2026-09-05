#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n; cin >> n;
    vector<int> S(n);
    for(auto &s : S) cin >> s;

    vector<int> pr(n + 1, 0), sf(n + 1, 0);
    for(int i = 0; i < n; i++){
        pr[i + 1] = pr[i] + (S[i] == 0 ? 1 : 0);
        sf[n - 1 - i] = sf[n - i] + S[n - 1 - i];
    }

    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans, pr[i] + sf[i]);
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}