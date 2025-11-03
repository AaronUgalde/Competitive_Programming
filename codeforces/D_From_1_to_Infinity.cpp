#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

ll gauss(ll n){
    return n * (n + 1) / 2;
}

void solve(int testcase){
    ll k; cin >> k;
    ll last = 1;
    ll cnt = 1;
    ll curr = 0;
    ll ans = 0;
    while(k > 0){
        last = cnt * last * 9;
        if(k - last < 0){
            curr += k / cnt;
            cout << " curr: " << curr << endl;
            ans = gauss(curr);
            k %= cnt;
            string curr_1 = to_string(curr + 1);
            for(int i = 0; i < k; i++) ans += curr_1[i] - '0';
            cout << ans << endl;
            return;
        }
        k -= last;
        curr = pow(10, cnt) - 1;
        cnt++;
        cout << " last: " << last << " cnt: " << cnt << " curr: " << curr << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}