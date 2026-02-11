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
    vector<pair<int, int>> coords(n), dirs(n);
    for(auto &c : coords) cin >> c.first >> c.second;
    for(auto &d : dirs) cin >> d.first >> d.second;

    vector<pair<int, int>> from_zero_other;
    for(int i = 1; i < n; i++){
        from_zero_other.emplace_back(dirs[i].first - dirs[0].first, dirs[i].second - dirs[0].second);
    }
    sort(all(from_zero_other));

    for(int i = 0; i < n; i++){
        vector<pair<int, int>> from_i_other;
        for(int j = 0; j < n; j++){
            if(j != i)
                from_i_other.emplace_back(coords[i].first - coords[j].first, coords[i].second - coords[j].second);
        }
        sort(all(from_i_other));
        
        bool is_equal = true;
        for(int j = 0; j < sz(from_i_other); j++){
            if(from_zero_other[j] != from_i_other[j]){
                is_equal = false;
                break;
            }
        }

        if(is_equal){
            cout << coords[i].first + dirs[0].first << ' ' << coords[i].second + dirs[0].second << endl;
            return;
        }
    }


}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}