#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int T, X; cin >> T >> X;
    vector<int> A(T + 1);
    for(auto &a : A) cin >> a;

    vector<pair<int, int>> ans;
    ans.emplace_back(0, A[0]);
    for(int i = 1; i <= T; i++){
        if(abs(A[i] - ans[sz(ans) - 1].second) >= X){
            ans.emplace_back(i, A[i]);
        }
    }

    for(auto &a : ans) cout << a.first << ' ' << a.second << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}