#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n, k; cin >> n >> k;
    vector<ll> powers(32, 0);

    ll cnt = n;
    powers[0] = n;
    int i = 0;
    while(cnt > k and i < 32){
        if(powers[i] >= 2){
            cnt--;
            powers[i] -= 2;
            powers[i + 1]++;
        }else{
            i++;
        }
    }

    if(cnt != k){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < powers[i]; j++){
            cout << (1 << i) << ' ';
        }
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