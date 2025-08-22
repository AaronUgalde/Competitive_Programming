#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    int ans = 0;
    sort(all(a), greater<int>());
    while(a[0] > 0 && a[1] > 0){
        a[0]--;
        a[1]--;
        sort(all(a), greater<int>());        
        ans++;
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