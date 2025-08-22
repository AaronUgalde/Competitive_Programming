#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<bool> rows(n, false), columns(n, false);

    for(int i = 0; i<m; i++){
        int x, y; cin >> x >> y; x--; y--;
        rows[x] = true; columns[y] = true;
    }

    int column = false, row = false;
    for(int i = 0; i<n; i++){
        if(rows[i] == false) row = true;
        if(columns[i] == false) column = true;
    }


    cout << ((row || column )? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}