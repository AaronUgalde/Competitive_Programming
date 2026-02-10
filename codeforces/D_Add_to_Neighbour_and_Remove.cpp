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
    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    ll sum = accumulate(all(A), 0ll);
    ll ans = n - 1;
    for(int i = 2; i <= n; i++){
        if(sum % i != 0) continue;
        ll div = sum / i;
        ll curr_sum = 0;
        bool flag = true;
        for(int j = 0; j < n; j++){
            curr_sum += A[j];
            if(curr_sum > div){
                flag = false;
                break;
            }else if(curr_sum == div){
                curr_sum = 0;
            }
        }
        if(flag){
            ans = n - i;
        }
    }

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