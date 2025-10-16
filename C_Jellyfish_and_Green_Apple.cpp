#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, m; cin >> n >> m;
    n %= m;
    int N = n / gcd(n, m);
    int M = m / gcd(n, m);
    if(__builtin_popcount(M) > 1){
        cout << -1 << endl;
        return;
    }

    cout << 1ll * __builtin_popcount(N) * m - n << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}