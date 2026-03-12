#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    ull k, x; cin >> k >> x;

    auto emotes = [&](ull y){
        if(y > k){
            ull d = y - k;
            return k * (k + 1) / 2 + d * k - (d * (d + 1) / 2);
        }else{
            return y * (y + 1) / 2;
        }
    };

    auto check = [&](ull y){
        ull n_emotes = emotes(y);
        return n_emotes < x;
    };

    ull l = 0, r = 2 * k;
    while(r - l > 1){
        ull m = midpoint(l, r);
        if(check(m)){
            l = m;
        }else{
            r = m;
        }
    }

    cout << min(2 * k - 1, r) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}