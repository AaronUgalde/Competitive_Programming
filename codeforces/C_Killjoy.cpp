#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n, x; cin >> n >> x;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    int balance = 0;
    bool all_x = true;
    bool one_x = false;
    for(auto &a : A){
        if(a != x) all_x = false;
        else one_x = true;
        balance += x - a;
    }

    cout << (all_x ? 0 : balance == 0 or one_x ? 1 : 2) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}