#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    sort(all(A));
    ll sum = accumulate(all(A), 0ll);
    
    if(sum <= k){
        cout << 0 << endl;
        return;
    }

    sum -= A[0];
    ll min_operations = INT_MAX;
    for(int i = n - 1; i >= 0; i--){
        ll diff_k = k - sum;
        ll diff_min;
        if(diff_k < 0){
            diff_min = (diff_k - (n - i - 1)) / (n - i);
        }else{
            diff_min = diff_k / (n - i);
        }
        ll mn_0 = (diff_min >= A[0] ? 0 : A[0] - diff_min);
        min_operations = min(min_operations, mn_0 + n - i - 1);
        sum -= A[i];
    }

    cout << min_operations << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}