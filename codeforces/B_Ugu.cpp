#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;
    bool same = true;
    int greatest = 0;
    int ans = 0;
    for(int i = 0; i<n; i++){
        s[i] = (same ? s[i] : '0' + (s[i] - '0' + 1) % 2);
        if(s[i] - '0' < greatest){
            ans++;
            same = !same;
        }
        greatest = max(greatest, s[i] - '0');
    }

    println("{}", ans);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}