#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n; cin >> n;
    vector<ll> C(n);
    for(auto &c : C) cin >> c;

    ll ones = 0;
    ll sum = 0;
    ll free_space = 0;
    for(auto &c : C){
        if(c > 1){
            sum += c;
            free_space += c / 2 - 1;
        }else{
            ones++;
        }
    }

    if(ones == n - 1) free_space++;

    cout << (sum + min(free_space, ones) >= 3 ? sum + min(free_space, ones) : 0)  << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}