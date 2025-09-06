#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n, m, x, y, d; cin >> n >> m >> x >> y >> d;
    
    if((x - d <= 1 || y + d >= m) && (x + d >= n || y - d <= 1)){
        cout << -1 << endl;
        return;
    }

    cout << n - 1 + m - 1 << endl; 
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}