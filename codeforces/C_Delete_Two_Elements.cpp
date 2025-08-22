#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    ll n; cin >> n;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    ll sum = accumulate(all(A), 0ll);
    if((sum * 2) % n != 0){
        cout << 0 << endl;
        return;
    }

    map<ll, ll> num_frec;
    for(auto &a : A){
        num_frec[a]++;
    }

    ll target = sum * 2 / n;
    ll ans = 0;
    for(auto &[num, frec] : num_frec){
        int res = target - num;
        if(!num_frec.count(res)) continue;
        if(res == num){
            ans += frec*(frec-1)/2;
        }else{
            ans += frec * num_frec[res];
            num_frec[res] = 0;
        }
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