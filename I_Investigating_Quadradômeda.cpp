#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<pair<ll, ll>> stars(n);
    for(auto &star : stars) cin >> star.first >> star.second;

    vector<ll> d(n - 1);
    for(int i = 0; i < n - 1; i++){
        d[i] = (stars[i].first != stars[i + 1].first ? abs(stars[i].first - stars[i + 1].first) : abs(stars[i].second - stars[i + 1].second));
    }

    ll a = 1, b = 0;
    ll low = LLONG_MIN, high = LLONG_MAX;
    for(int i = 0; i < n; i++){
        if(a == 1){
            low = max(low, 1 - b);
            if(i < n - 1) high = min(high, d[i] - 1 -b);
        }else{
            high = min(high, b - 1);
            if(i < n - 1) low = max(low, b + 1 - d[i]);
        }
        a = -a;
        if(i < n - 1) b = d[i] - b; 
    }

    if(low <= high) cout << high << endl;
    else cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}