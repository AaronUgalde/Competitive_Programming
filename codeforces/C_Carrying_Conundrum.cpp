#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    string n; cin >> n;

    int a = 0, b = 0;
    reverse(all(n));
    for(int i = 0; i < sz(n); i++){
        if(i % 2 == 0) a += (n[i] - '0') * pow(10, i / 2);
        else b += (n[i] - '0') * pow(10, i / 2);
    }

    cout << (a + 1) * (b + 1) - 2 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}