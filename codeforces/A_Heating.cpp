#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int c, s; cin >> c >> s;
    int mn_per_radiator = s/c;
    int mod = s%c;
    cout << (mn_per_radiator) * (mn_per_radiator) * (c - mod) + (mn_per_radiator + 1) * (mn_per_radiator + 1) * mod << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}