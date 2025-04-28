#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n, l; cin >> n >> l;
    vector<int> lanterns(n);
    for(auto &l : lanterns) cin >> l;
    
    sort(lanterns.begin(), lanterns.end());
    lanterns.push_back(l + (l - lanterns[n - 1]));

    int maxD = INT_MIN;
    int lastLantern = -lanterns[0];
    for(auto &l : lanterns){
        int d = l - lastLantern;
        maxD = max(maxD, d);
        lastLantern = l;
    }

    cout << fixed << setprecision(9) <<  maxD / 2.0 << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}