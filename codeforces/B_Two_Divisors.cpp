#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    ll a, b; cin >> a >> b;
    if(b % a == 0){
        ll p = b/a;
        cout << (b * p) << endl;
    }else{
        cout << ((a*b)/gcd(a,b)) << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}