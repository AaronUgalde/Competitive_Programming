#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    string first, last; cin >> first >> last;
    string ans = first.substr(0, 1);
    for(int i = 1; i < sz(first); i++){
        if(first[i] >= last[0]) break;
        ans += first[i];
    }

    cout << ans << last[0] << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}