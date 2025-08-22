#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    ll n, x, y; cin >> n >> x >> y;
    string s; cin >> s;
    int last_one_idx = -1;
    int segments_zero = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '1'){
            if(i - last_one_idx - 1 > 0) segments_zero++;
            last_one_idx = i;
        }
    }

    if(n - last_one_idx - 1 > 0) segments_zero++;

    if(segments_zero == 0){
        cout << 0 << endl;
        return;
    }

    ll ans = y;
    segments_zero--;

    ans += min(x, y) * segments_zero;

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}