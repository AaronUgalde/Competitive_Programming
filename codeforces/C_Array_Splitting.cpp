#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, k; cin >> n >> k;
    vector<int> A(n);
    for(auto &a : A) cin >> a;
    vector<int> diff(n - 1);
    for(int i = 1; i < n; i++){
        diff[i - 1] = A[i - 1] - A[i];
    }

    sort(all(diff));
    int ans = A[n - 1] - A[0];
    for(int i = 1; i < k; i++){
        ans += diff[i - 1];
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}