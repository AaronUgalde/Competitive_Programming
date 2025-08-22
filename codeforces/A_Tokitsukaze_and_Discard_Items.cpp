#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> P(m);
    for(auto &p : P) cin >> p;
    
    ll first = 0;
    ll offset = 0;
    ll operations = 0;

    while(first < m){
        ll t = first;
        if(P[first] - first == 0) offset = 1;
        else offset = (P[first] - first) / k + ((P[first] - first) % k > 0);
        while(first < m && P[first] <= offset*k + t) first++;
        operations++;
    }

    cout << operations << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}