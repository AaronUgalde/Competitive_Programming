#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    string n; cin >> n;
    
    vector<ll> squares(44721);
    for(ll i = 1; i <= 44721; i++){
        squares[i - 1] = i * i;
    }

    for(ll i = sz(squares) - 1; i >= 0; i--){
        string s_square = to_string(squares[i]);
        int j = 0;
        for(int k = 0; j < sz(s_square) and k < sz(n); k++){
            if(s_square[j] == n[k]) j++;
        }
        if(j == sz(s_square)){
            cout << sz(n) - sz(s_square) << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}