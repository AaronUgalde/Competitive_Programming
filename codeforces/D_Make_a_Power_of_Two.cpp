#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    string n; cin >> n;

    ll ans = INT_MAX;
    for(ll i = 0; (1ll << i) <= 1e18; i++){
        string pot2 = to_string(1ll << i);
        ll j_pot2 = 0;
        for(ll j_n = 0; j_n < sz(n); j_n++){
            if(j_pot2 < sz(pot2) and n[j_n] == pot2[j_pot2]){
                j_pot2++;
            }
        }
        ll deletions = sz(n) - (j_pot2);
        ll insertions = sz(pot2) - (j_pot2);
        //cout << " pot2: " << pot2 << " deletions: " << deletions << " insertions: " << insertions << endl;
        ans = min(ans, deletions + insertions);
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}