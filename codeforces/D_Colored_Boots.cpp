#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    string l, r; cin >> l >> r;
    map<char, vector<int>> balance;

    for(int i = 0; i < n; i++){
        balance[l[i]].push_back(i);
    }

    vector<pair<int, int>> p_boots;
    vector<int> right_undefined;
    for(int i = 0; i < n; i++){
        if(r[i] == '?'){
            right_undefined.push_back(i);
        }else if(balance[r[i]].size() > 0){
            p_boots.emplace_back(balance[r[i]][sz(balance[r[i]]) - 1], i);
            balance[r[i]].pop_back();
        }else if(balance['?'].size() > 0){
            p_boots.emplace_back(balance['?'][sz(balance['?']) - 1], i);
            balance['?'].pop_back();
        }
    }

    for(auto &[c, v] : balance){
        if(sz(right_undefined) == 0){
            break;
        }
        while(sz(v) > 0 and sz(right_undefined) > 0){
            p_boots.emplace_back(v[sz(v) - 1], right_undefined[sz(right_undefined) - 1]);
            v.pop_back();
            right_undefined.pop_back();
        }
    }

    cout << sz(p_boots) << endl;
    for(auto &[a, b] : p_boots){
        cout << a + 1 << ' ' << b + 1 << endl;
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}