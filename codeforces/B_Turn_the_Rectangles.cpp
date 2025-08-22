#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<pair<int, int>> rec(n);
    for(auto &r : rec) cin >> r.first >> r.second;

    int last = max(rec[0].first, rec[0].second);
    for(int i = 1; i<n; i++){
        if(max(rec[i].first, rec[i].second) <= last){
            last = max(rec[i].first, rec[i].second);
        }else if(min(rec[i].first, rec[i].second) <= last){
            last = min(rec[i].first, rec[i].second);
        }else{
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}