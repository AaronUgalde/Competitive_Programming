#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    string s; cin >> s;
    set<char> c;
    set<char> d;
    for(auto &x : s){
        if(d.count(x)) c.erase(x);
        else c.insert(x), d.insert(x);
    }  

    cout << *c.begin() << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}