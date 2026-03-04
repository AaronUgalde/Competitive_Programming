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
    cout << 3 * n + 4 << endl;
    pair<int, int> a = {0, 0}, b = {0, 1}, c = {1, 0};
    for(int i = 0; i <= n; i++){
        cout << a.first << ' ' << a.second << endl;
        cout << b.first << ' ' << b.second << endl;
        cout << c.first << ' ' << c.second << endl;
        a.first += 1; a.second += 1;
        b.first += 1; b.second += 1;
        c.first += 1; c.second += 1;
    }

    cout << a.first << ' ' << b.first << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}