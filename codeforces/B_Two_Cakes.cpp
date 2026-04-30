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
    
    auto min_pieces = [&](int x, int y){
        return x / y;
    };

    int mx = INT_MIN;
    for(int i = 1; i < n; i++){
        int min_a = min_pieces(a, i);
        int min_b = min_pieces(b, n - i);
        mx = max(mx, min(min_a, min_b));
    }

    cout << mx << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}