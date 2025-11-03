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
    
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '>') break;
        a++;
    }

    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '<') break;
        b++;
    }

    cout << min(a, b) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}