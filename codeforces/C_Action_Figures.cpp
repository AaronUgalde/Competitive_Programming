#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    ll ans = n * (n + 1) / 2;
    deque<int> discounts;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '1'){
            discounts.emplace_front(i + 1);
        }else if(!discounts.empty()){
            ans -= discounts.back();
            discounts.pop_back();
        }
    }

    while(discounts.size() > 1){
        ans -= discounts.back();
        discounts.pop_front();
        discounts.pop_back();
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}