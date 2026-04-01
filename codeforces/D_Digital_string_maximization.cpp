#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    string s; cin >> s;
    
    for(int i = 0; i < sz(s); i++){
        int cnt = 0;
        int cnt_mx = cnt;
        for(int j = i; j < sz(s) and cnt <= 10; j++, cnt++){
            if(s[i + cnt] - '0' - cnt > s[cnt_mx + i] - '0' - cnt_mx){
                cnt_mx = cnt;
            }
        }
        rotate(s.begin() + i, s.begin() + i + cnt_mx, s.begin() + i + cnt_mx + 1);
        s[i] -= cnt_mx;
    }

    cout << s << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}