#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
 ll n, k; 
    cin >> n >> k;
    vector<ll> A(n);
    ll sum_a = 0;
    for(auto &a : A) { cin >> a; sum_a += a; }

    ll mx = *max_element(all(A));

    auto can_s = [&](int s) -> bool {
        if (s <= 0) return false;
        ll need = 1LL * s * mx;
        if (need > sum_a) return (need - sum_a) <= k;
        ll rem = sum_a % s;
        ll delta = (rem == 0 ? 0 : (s - rem)); 
        return delta <= k;
    };

    for (int s = (int)n; s >= 1; --s) {
        if (can_s(s)) {
            cout << s << '\n';
            return;
        }
    }

    cout << 0 << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}