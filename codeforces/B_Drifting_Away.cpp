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
    int n = sz(s);

    int left = 0, right = 0;
    for(int i = 0; i < n and s[i] == '<'; i++){
        left++;
    }
    for(int i = n - 1; i >= 0 and s[i] == '>'; i--){
        right++;
    }

    if(left + right >= n - 1) cout << max(left, right) + (n - left - right) << endl;
    else cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}