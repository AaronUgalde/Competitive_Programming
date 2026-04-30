#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    ll k, a, b; cin >> k >> a >> b;
    ll win_a = a / k; a %= k;
    ll win_b = b / k; b %= k;
    cout << (a == 0 or b == 0 or (win_a and win_b) ? win_a + win_b : -1) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}