#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n, r; cin >> n >> r;
    vector<pair<double, double>> coords(n);
    for(auto &coord : coords) cin >> coord.first;

    cout << fixed << setprecision(11);
    for(int i = 0; i < n; i++){
        double max_y = r;
        for(int j = 0; j < i; j++){
            double ca = abs(coords[i].first - coords[j].first);
            if(abs(coords[i].first - coords[j].first) > 2 * r) continue;
            double h = 2 * r; 
            double theta = acos(ca / h);
            double co = h * sin(theta);
            max_y = max(max_y, coords[j].second + co);
        }
        coords[i].second = max_y;
        cout << max_y << ' ';
    }

    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}