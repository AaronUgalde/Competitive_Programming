#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    ll n, c, d; cin >> n >> c >> d;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    sort(all(A), greater<int>());

    auto check = [&](int m){
        ll sum = 0;
        for(int i = 0, j = 0; i < d; i++, j = (j + 1) % (m + 1)){
            if(j < n) sum += A[j];
        }
        return sum >= c;
    };

    ll l = -1, r = d + 1;
    while(r - l > 1){
        ll m = (l - r) / 2 + r;
        if(check(m))
            l = m;
        else
            r = m;
    }

    if(l == -1){
        cout << "Impossible" << endl;
    }else if(l >= d){
        cout << "Infinity" << endl;
    }else{
        cout << l << endl;
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