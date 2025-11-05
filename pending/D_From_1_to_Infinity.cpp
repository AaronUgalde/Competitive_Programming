#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

ll gauss(ll n){
    return n * (n + 1) / 2;
}

void solve(int testcase){
    ll k;
    cin >> k;
    ll cur = 9, len = 1;
    while (k - cur * len > 0) {
        k -= cur * len;
        cur *= 10;
        len++;
    }
    string s = to_string(cur / 9 + (k - 1) / len);
    ll ans = 0;
    for (int i = 0; i < (k - 1) % len + 1; i++)
        ans += s[i] - '0';

    for(int i = 0; i < len; i++){
        
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}