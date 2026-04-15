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

    string ans = "";
    for(int i = 0; i < k; i++){
        for(int j = i; j < k; j++){
            ans += char(j + 'a');
            if(j != k - 1) ans += char(i + 'a');
        }
    }

    for(int cnt = 0, i = 0; cnt < n; cnt++, i = (i + 1) % sz(ans)){
        cout << ans[i];
    }

    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}