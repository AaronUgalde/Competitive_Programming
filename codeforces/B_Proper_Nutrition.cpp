#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n, a, b; cin >> n >> a >> b;
    for(int i = 0; i <= n / a; i++){
        if((n - a * i) % b == 0){
            cout << "YES" << endl;
            cout << i << ' ' << (n - a * i ) / b << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}