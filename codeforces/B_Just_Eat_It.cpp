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

    auto kadane = [&](int start, int end)->ll{
        ll ans = INT_MIN;
        ll curr = INT_MIN;
        ll sum = 0;
        for(int i = start; i < end; i++){
            sum += A[i];
            if(sum < 0) sum = 0;
            curr = max(sum, curr);
            ans = max(curr, ans);
        }
        return ans;
    };

    cout << (max(kadane(1, n), kadane(0, n - 1)) >= accumulate(all(A), 0ll) ? "NO" : "YES") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}