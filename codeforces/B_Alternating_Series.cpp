#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        if(i % 2 == 0) cout << -1 << ' ';
        else{
            if(i == n-1) cout << 2 << ' ';
            else cout << 3 << ' ';
        }
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}