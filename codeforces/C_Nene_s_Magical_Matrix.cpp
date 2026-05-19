#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    ll n; cin >> n;
    
    ll ans = 0;
    for(int i = n, j = 2 * n - 1; i >= 1; i--, j -= 2){
        ans += i * j;
    }

    cout << ans << ' ' << 2 * n << endl;

    for(int i = 0; i < n; i++){
        cout << 1 << ' ' << (i + 1) << ' ';
        for(int i = n; i >= 1; i--){
            cout << i << ' ';
        }
        cout << endl;
        cout << 2 << ' ' << (i + 1) << ' ';
        for(int i = n; i >= 1; i--){
            cout << i << ' ';
        }
        cout << endl;
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}