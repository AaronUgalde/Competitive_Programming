#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n, k; cin >> n >> k;
    vector<ll> A(n*k);
    for(auto &a : A) cin >> a;

    sort(all(A), greater<int>());
    int pos = n/2 + 1;
    ll ans = 0;
    int take = 0;

    for(int i = 0; i<(n*k) && take < k; i++){
        if(i % pos == pos - 1){
            ans += A[i];
            take++;
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