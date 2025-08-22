#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(ll testcase){
    ll n, x; cin >> n >> x;
    vector<vector<ll>> stacks(3, vector<ll>(n));
    for(auto &V : stacks)
        for(auto &v : V) cin >> v;

    ll k = 0;

    if(k == x){
        cout << "Yes" << endl;
        return;
    }

    for(ll i = 0; i<3; i++){
        for(ll j = 0; j<n; j++){
            if((x | stacks[i][j]) == x) k |= stacks[i][j];
            else break;
            if(k == x){
                cout << "Yes" << endl;
                return;
            }
        }
    }

    cout << "No" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll t = 1;
    cin >> t;
    for(ll i = 0; i<t; i++){
        solve(i);
    }
}

