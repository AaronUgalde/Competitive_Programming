#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;
    set<char> distinct;
    vector<int> prefix(s.size());
    for(int i = 0; i<s.size(); i++){
       distinct.insert(s[i]);
       prefix[i] = distinct.size(); 
    }

    cout << accumulate(all(prefix), 0) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}