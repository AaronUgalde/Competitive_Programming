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
    
    map<char, int> c_frec;
    for(auto &c : s){
        c_frec[c]++;
    }

    char max_c;
    int frec = 0;
    for(auto &[c, f] : c_frec){
        if(f >= frec){
            frec = f;
            max_c = c;
        }
    }

    if(max_c == 'R') cout << string(sz(s), 'P') << endl;
    else if(max_c == 'P') cout << string(sz(s), 'S') << endl;
    else if(max_c == 'S') cout << string(sz(s), 'R') << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}