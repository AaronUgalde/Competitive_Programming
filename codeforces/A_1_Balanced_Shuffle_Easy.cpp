#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    string s; cin >> s;
    vector<pair<int, int>> balanced_shuffle(s.size());
    balanced_shuffle[0] = {0, 0};
    for(int i = 0; i<s.size()-1; i++){
        if(s[i] == '(') balanced_shuffle[i+1] = {balanced_shuffle[i].first + 1, -(i + 1)};
        else balanced_shuffle[i+1] = {balanced_shuffle[i].first - 1, -(i + 1)};
    }

    sort(all(balanced_shuffle));
    for(int i = 0; i<balanced_shuffle.size(); i++){
        cout << s[-balanced_shuffle[i].second];
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