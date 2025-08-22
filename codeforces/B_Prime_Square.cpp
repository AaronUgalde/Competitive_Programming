#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<int> row(n, 0);
    row[0] = 1;
    row[1] = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << row[j] << ' ';
        }
        cout << endl;
        rotate(row.begin(), row.begin() + 1, row.end());
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