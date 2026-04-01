#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    string s; cin >> s;
    vector<ll> x;
    int cnt = 0;
    for(int i = 0; i < sz(s); i++){
        if(s[i] == 'o'){
            x.emplace_back(max(0, cnt - 1));
            cnt = 0;
        }else{
            cnt++;
        }
    }
    x.emplace_back(max(0, cnt - 1));

    vector<ll> prefix(sz(x) + 1, 0);
    for(int i = 0; i < sz(x); i++){
        prefix[i + 1] = prefix[i] + x[i];
    }

    ll ans = 0;
    for(int i = 1; i < sz(prefix); i++){
        ans += (prefix[sz(prefix) - 1] - prefix[i - 1]) * (prefix[i - 1]);
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}