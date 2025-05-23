#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n, m; cin >> n >> m;
    int lastPerson = INT_MAX;
    vector<pair<int, int>> persons;
    for(int i = 0; i<n; i++){
        int person; cin >> person;
        if(person < lastPerson){
            persons.push_back({person, i});
            lastPerson = person;
        }
    }

    vector<pair<int, int>> sushis(m);
    for(int i = 0; i<m; i++){
        int sushi; cin >> sushi;
        sushis[i] = {sushi, i};
    }

    sort(sushis.begin(), sushis.end(), 
        [](auto const &a, auto const &b){
            return a.first > b.first;
        }
    );

    map<int, int> whoEatsSushi;
    n = persons.size();
    int j = 0;
    for(int i = 0; i<m; i++){
        if(sushis[i].first >= persons[j].first){
            whoEatsSushi[sushis[i].second] = persons[j].second;
        }else{
            while(j < n && persons[j].first > sushis[i].first){
                j++;
            }
            if(j < n){
                whoEatsSushi[sushis[i].second] = persons[j].second;
            }
        }

        if(j >= n){
            whoEatsSushi[sushis[i].second] = -1;
        }
    }

    for(int i = 0; i<m; i++){
        cout << (whoEatsSushi[i] > -1 ? whoEatsSushi[i] + 1 : -1) << '\n';
    }

    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}