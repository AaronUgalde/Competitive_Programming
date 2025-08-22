#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    string s, t; cin >> s >> t;
    map<char, int> t_pos;
    int n = s.size(), m = t.size();
    for(int i = 0; i<m-1; i++){
        t_pos[t[i]] = i;
    }
    
    ll best_i = -1, best_j = -1, best_size = INT_MAX;
    for(int i = 1; i<n; i++){
        char key = s[i];
        int pos_s = i;
        if(!t_pos.count(key)) continue;
        ll pos_t = t_pos[key];
        if(pos_s + m - 1 - pos_t <= best_size && (pos_s > 0 && pos_t < m - 1)){
            best_size = pos_s + m - 1 - pos_t;
            best_i = pos_s;
            best_j = pos_t;
        }
    }

    if(best_i == -1 || best_j == -1){
        cout << -1 << endl;
        return;
    }

    string ans = s.substr(0, best_i) + t.substr(best_j);

    cout << (ans.size() > s.size() + t.size() ? "-1" : ans) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}