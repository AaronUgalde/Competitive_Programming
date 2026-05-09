#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n, k; cin >> n >> k;
    vector<int> H(n);
    for(auto &h : H) cin >> h;

    vector<pair<int, int>> memo(n);
    memo[0] = {H[0], H[0]};
    for(int i = 1; i < n; i++){
        int mn = max(H[i], memo[i - 1].first - (k - 1));
        int mx = min(H[i] + (k - 1), memo[i - 1].second + k - 1);
        if(mn > mx){
            cout << "NO" << endl;
            return;
        }
        memo[i] = {mn, mx};
    }

    if(memo[n - 1].first > H[n - 1] or memo[n - 1].second < H[n - 1]){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}