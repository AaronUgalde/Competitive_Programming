#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    if(!(cin >> n)) return;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    ll c_plus = LLONG_MIN, c_minus = LLONG_MIN;
    for(int i = 0; i < n - 1; ++i){
        ll diff = A[i+1] - A[i];
        if(diff >= 0){
            if(c_plus == LLONG_MIN) c_plus = diff;
            else if(c_plus != diff){ cout << -1 << '\n'; return; }
        }else{
            if(c_minus == LLONG_MIN) c_minus = diff;
            else if(c_minus != diff){ cout << -1 << '\n'; return; }
        }
    }

    if(c_plus == LLONG_MIN || c_minus == LLONG_MIN){
        cout << 0 << '\n';
        return;
    }

    ll m = c_plus - c_minus;

    ll maxA = *max_element(A.begin(), A.end());
    if(m <= 0 || m <= maxA){
        cout << -1 << '\n';
        return;
    }

    for(int i = 0; i < n - 1; ++i){
        ll expected = (A[i] + c_plus) % m;
        if(expected != A[i+1]){
            cout << -1 << '\n';
            return;
        }
    }

    cout << m << ' ' << c_plus << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
