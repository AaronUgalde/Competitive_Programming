#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<ll> P(n);
    for(auto &p : P) cin >> p;

    int m; cin >> m;
    vector<ll> Q(m);
    for(auto &q : Q) cin >> q;

    ll p_odds = 0;
    ll p_evens = 0;
    ll q_odds = 0;
    ll q_evens = 0;
    for(int i = 0; i<n; i++){
        if(P[i] % 2 == 0) p_evens++;
        else p_odds++;
    }
    for(int i = 0; i<m; i++){
        if(Q[i] % 2 == 0) q_evens++;
        else q_odds++;
    }

    cout << (p_evens * q_evens + p_odds * q_odds)<< endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}