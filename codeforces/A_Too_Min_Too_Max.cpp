#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    sort(all(a));
    int ans = 0;
    ans += abs(a[0] - a[n-1]);
    ans += abs(a[1] - a[n-1]);
    ans += abs(a[1] - a[n-2]);
    ans += abs(a[0] - a[n-2]);
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