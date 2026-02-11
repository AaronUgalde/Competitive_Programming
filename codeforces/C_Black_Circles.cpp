#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

ll dist(ll x_1, ll y_1, ll x_2, ll y_2){
    return (x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2);
}

void solve(int testcase){
    int n; cin >> n;
    vector<ll> X(n), Y(n);
    for(int i = 0; i < n; i++){
        cin >> X[i] >> Y[i];
    }
    ll x_s, y_s, x_t, y_t;
    cin >> x_s >> y_s >> x_t >> y_t;

    for(int i = 0; i < n; i++){
        if(dist(X[i], Y[i], x_t, y_t) <= dist(x_s, y_s, x_t, y_t)){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}