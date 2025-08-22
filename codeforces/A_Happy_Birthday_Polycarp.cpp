#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    ll n; cin >> n;

    vector<ll> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ll ans = 0;
    for(int i = 0; i<9; i++){
        ll beautiful = numbers[i];
        ll ten_pow = 1;
        while(beautiful <= n){
            ans++;
            ten_pow *= 10;
            beautiful += numbers[i] * ten_pow;
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}