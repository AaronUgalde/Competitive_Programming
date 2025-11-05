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
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    int mx = INT_MIN;
    for(int i = 0; i < n; i++){
        mx = max(mx, A[i]);
        if(i % 2 == 1) A[i] = mx;
    }

    ll ans = 0;
    for(int i = 0; i < n; i += 2){
        int left = (i == 0 ? INT_MAX : A[i - 1]);
        int right = (i == n - 1 ? INT_MAX : A[i + 1]);
        int mn = min(left, right);
        if(A[i] >= mn){
            ans += A[i] - mn + 1;
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