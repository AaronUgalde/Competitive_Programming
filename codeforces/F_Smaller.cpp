#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int q; cin >> q;
    string s = "a", t = "a";
    ll a_balance = 0;
    bool s_has_not_a = false;
    bool t_has_not_a = false;
    for(int i = 0; i < q; i++){
        ll d, k; cin >> d >> k;
        string x; cin >> x;
        if(d == 1){
            for(auto &c : x){
                if(c == 'a') a_balance += k;
                else s_has_not_a = true;
            }
        }else{
            for(auto &c : x){
                if(c == 'a') a_balance -= k;
                else t_has_not_a = true;
            }
        }

        if(t_has_not_a){
            cout << "YES" << endl;
        }else if(s_has_not_a){
            cout << "NO" << endl;
        }else{
            cout << (a_balance >= 0 ? "NO" : "YES") << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}