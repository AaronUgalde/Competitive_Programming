#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

ll gaus_sum(ll n){
    return n * (n+1) / 2;
}

ll range_sum(ll l, ll r){
    return gaus_sum(r) - gaus_sum(l-1);
}

void solve(int testcase){
    ll n, k; cin >> n >> k;

    ll lo = 1, hi = n;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        ll left  = range_sum(k,     k + mid - 1);
        ll right = range_sum(k + mid, k + n - 1);
        if (left < right)
            lo = mid + 1;
        else
            hi = mid;
    }

    ll best = min(
        abs(range_sum(k,     k + lo - 1)
            - range_sum(k + lo, k + n - 1)),
        abs(range_sum(k,     k + lo - 2)
            - range_sum(k + lo - 1, k + n - 1))
    );

    cout << best << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}