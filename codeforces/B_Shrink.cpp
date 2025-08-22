#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> p(n);
    p[n-1] = 2;
    p[0] = 1;
    for(int i = 1; i<n-1; i++){
        p[i] = i+2;
    }

    for(auto &x : p) cout << x << ' ';
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