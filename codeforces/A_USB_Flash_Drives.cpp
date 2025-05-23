#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<int> usbs(n);
    for(auto &usb : usbs) cin >> usb;

    sort(all(usbs), greater<int>());
    int ans = 0;
    for(auto &usb : usbs){
        m -= usb;
        ans++;
        if(m <= 0) break;
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