#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    int k; cin >> k;
    vector<pair<int, int>> monsters(n);
    for(auto &p : monsters) cin >> p.first;
    for(auto &p : monsters) cin >> p.second;

    vector<pair<int, int>> clean_monsters;
    sort(all(monsters), [](const pair<int, int> &a, const pair<int, int> &b){
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    int curr_min_power = INT_MAX;
    for(auto &[health, power] : monsters){
        if(power < curr_min_power){
            clean_monsters.emplace_back(health, power);
            curr_min_power = power;
        }
    }

    sort(all(clean_monsters));

    //for(auto &monster : clean_monsters) cout << "[" << monster.first << ' ' << monster.second << ']' << endl;

    int i = 0;
    int curr_damage = 0;
    while(k > 0){
        //cout << "k: " << k << " curr_damage_ " << curr_damage << " i: " << i << endl;
        curr_damage += k;
        while(i < clean_monsters.size() && curr_damage >= clean_monsters[i].first) i++;
        if(i == clean_monsters.size()){
            cout << "YES" << endl;
            return;
        }
        k -= clean_monsters[i].second;
    }

    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}