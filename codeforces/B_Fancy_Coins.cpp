#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int m, k, a_1, a_k;
    cin >> m >> k >> a_1 >> a_k;

    int ones = min(m % k, a_1);
    a_1 -= ones;
    a_k += a_1 / k;
    a_1 = ones;

    int ans = (m % k) - a_1 + max(m / k - a_k, 0);
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