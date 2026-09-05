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
    vector<bool> used('z' - 'a' + 1, false);
    int ans = 0;
    for(int i = 0; i < sz(s); i++){
        if(used[s[i] - 'a'] == false) used[s[i] - 'a'] = true;
        else{
            ans += 2;
            fill(all(used), false);
        }
    }

    cout << sz(s) - ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}