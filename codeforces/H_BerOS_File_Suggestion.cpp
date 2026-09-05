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
    vector<string> F(n);
    for(auto &f : F) cin >> f;

    map<string, set<string>> mp;
    for(auto &f : F){
        for(int i = 0; i < sz(f); i++){
            for(int j = 1; j <= sz(f) - i; j++){
                mp[f.substr(i, j)].insert(f);
            }
        }
    }

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        string s; cin >> s;
        if(!mp.count(s)){
            cout << 0 << " -" << endl;
            continue;
        }
        cout << sz(mp[s]) << ' ' << *mp[s].begin() << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}