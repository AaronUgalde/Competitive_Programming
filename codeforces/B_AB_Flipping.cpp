#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;

    int mx_b = -1;
    int mn_a = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'B') mx_b = i;
        if(s[n - 1 - i] == 'A') mn_a = n - 1 - i;
    }

    
    cout << (mx_b != -1 and mn_a != -1 and mn_a < mx_b ? mx_b - mn_a : 0) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}