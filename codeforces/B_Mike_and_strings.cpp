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
    vector<string> S(n);
    for(auto &s : S) cin >> s;

    map<string, int> mp;
    set<string> visited1;
    for(int i = 0; i < sz(S[0]); i++){
        if(visited1.count(S[0])){
            break;
        }
        visited1.insert(S[0]);

        mp[S[0]] += i;
        rotate(S[0].begin(), S[0].begin() + 1, S[0].end());
    }

    for(int i = 1; i < n; i++){
        set<string> visited;
        for(int j = 0; j < sz(S[i]); j++){
            if(!mp.count(S[i])){
                cout << -1 << endl;
                return;
            }

            if(visited.count(S[i])){
                break;
            }

            visited.insert(S[i]);
            mp[S[i]] += j;
            rotate(S[i].begin(), S[i].begin() + 1, S[i].end());
        }
    }

    int mn = INT_MAX;
    for(auto &[string, cnt] : mp){
        mn = min(mn, cnt);
    }

    cout << mn << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}