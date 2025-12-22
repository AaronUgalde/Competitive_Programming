#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    ll n; cin >> n;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;
    sort(all(A));

    ll limit = 0;
    for(auto &a : A) limit += abs(a - 1);

    ll min_cost = LLONG_MAX;
    for(ll i = 1; abs(A[n - 1] - pow(i, n - 1)) <= limit; i++){
        ll cost = 0;
        for(ll j = 0; j < n; j++){
            cost += abs(A[j] - pow(i, j));
        }
        min_cost = min(min_cost, cost);
    }

    cout << min_cost << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}