#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, k; cin >> n >> k;
    vector<pair<int, int>> A(n);
    ll ans = 0;
    for(auto &[mod, a] : A){
        cin >> a;
        mod = a % k;
        ans += a / k;
    }

    sort(all(A));

    int l = 0, r = n - 1;
    while(r - l > 0){
        if(A[r].first + A[l].first >= k){
            ans++;
            l++;
            r--;
        }else{
            l++;
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