#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    ull n, k; cin >> n >> k;
    vector<ull> A(n);
    for(auto &a : A) cin >> a;
    
    ull ans = 0;
    ull k_used = 0;
    cout << fixed;
    for(int i = 0; i < n - 1; i++){
        int diff = A[i + 1] - A[i];
        ll curr_k = pow(10, diff) - 1;
        if(k_used + curr_k <= k){
            ans += pow(10, A[i]) * curr_k;
            k_used += curr_k;
        }else{
            ans += pow(10, A[i]) * (k - k_used + 1);
            k_used = k + 1;
            break;
        }
    }

    if(k_used <= k){
        ans += long(pow(10, A[n - 1])) * (k - k_used + 1);
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