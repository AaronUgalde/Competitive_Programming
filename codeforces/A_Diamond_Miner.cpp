#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    vector<ll> miners;
    vector<ll> diamonds;
    for(int i = 0; i < 2 * n; i++){
        ll x, y; cin >> x >> y;
        if(x == 0){
            miners.push_back(abs(y));
        }else{
            diamonds.push_back(abs(x));
        }
    }

    long double ans = 0;
    sort(all(miners));
    sort(all(diamonds));
    for(int i = 0; i < n; i++){
        ans += sqrt(miners[i] * miners[i] + diamonds[i] * diamonds[i]);
    }

    cout << setprecision(15) << fixed << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}