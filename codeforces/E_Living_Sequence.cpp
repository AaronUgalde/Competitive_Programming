#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

string base_9 (ll x){
    string y = "";
    while(x > 0){
        char z = (x%9 + '0');
        if(z >= '4') z++;
        y += z;
        x /= 9;
    }
    reverse(all(y));
    return y;
}

void solve(int testcase){
    ll k; cin >> k;
    cout << base_9(k) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}