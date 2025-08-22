#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    ll n, k; cin >> n >> k;
    ll diff = (n <  k - 1 ? k - 1 - n : 0);
    cout << ((k-1)/2 - diff > 0 ? (k-1)/2 - diff : 0) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}