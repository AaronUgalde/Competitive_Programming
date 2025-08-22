#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n, m, k; cin >> n >> m >> k;
    int a, b; cin >> a >> b;
    int c, d;
    bool can = false;
    for(int i = 0; i<k; i++){
        cin >> c >> d;
        if((abs(a - c) + abs(b-d)) % 2 == 0){
            can = true;
        }
    }

    cout << (can ? "NO" : "YES") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}