#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    string s; cin >> s;
    int i = 0, j = sz(s) - 1;
    vector<int> operation;
    while(i < j){
        while(i < sz(s) && s[i] != '(') i++;
        while(j >= 0 && s[j] != ')') j--;
        if(i < j){
            operation.push_back(i);
            operation.push_back(j);
            i++;
            j--;
        }
    }

    if(sz(operation) == 0){
        cout << 0 << endl;
        return;
    }

    cout << 1 << endl;
    sort(all(operation));
    cout << sz(operation) << endl;
    for(auto &i : operation) cout << i  + 1 << ' ';
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