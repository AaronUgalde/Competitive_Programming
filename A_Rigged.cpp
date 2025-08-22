#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    pair<int, int> poly; cin >> poly.first >> poly.second;
    int ans = poly.first;
    bool polycarp = true;
    for(int i = 1; i<n; i++){
        int s, e; cin >> s >> e;
        if(s >= poly.first && e >= poly.second) polycarp = false;
    }

    cout << (polycarp ? ans : -1) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}