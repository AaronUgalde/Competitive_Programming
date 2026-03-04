#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int k; cin >> k;

    int eights = k / 2;
    int nines = k % 2;
    string n = "111111111111111111";

    if(eights + nines > 18){
        cout << -1 << endl;
        return;
    }

    int i = 0;
    for(; eights and i < 18; i++, eights--){
        n[i] = '8';
    }
    for(; nines and i < 18; i++, nines--){
        n[i] = '9';
    }

    cout << n << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}