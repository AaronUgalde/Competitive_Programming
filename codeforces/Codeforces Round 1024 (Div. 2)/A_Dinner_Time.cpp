#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, m, p, q; cin >> n >> m >> p >> q;
    int np = n/p;
    int rem = n % p;
    //cout << " np: " << np << " npq " << np*q << endl;
    if(rem == 0 && np * q != m) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}