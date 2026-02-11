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
    int n_pearls = 0, n_strings = 0;
    for(auto &c : s){
        if(c == 'o') n_pearls++;
        else n_strings++;
    }

    if(n_pearls == 0){
        cout << "YES" << endl;
        return;
    }

    cout << (n_strings % n_pearls == 0 ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}