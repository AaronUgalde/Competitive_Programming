#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    ll n, m; cin >> n >> m;
    ll total = m * (m-1) / 2;

    vector<ll> cnt(n, 0);
    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        cnt[(a+b)%n]++;
    }

    for(int i = 0; i<n; i++){
        total -= cnt[i] * (cnt[i] - 1) / 2;
    }

    cout << total << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}