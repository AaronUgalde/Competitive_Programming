#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<pair<int, int>> shows(n);
    for(auto &show : shows) cin >> show.first >> show.second;

    int tv_1 = -1, tv_2 = -1;
    sort(all(shows));
    for(auto &[start, end] : shows){
        if(start > tv_1){
            tv_1 = end;
        }else if(start > tv_2){
            tv_2 = end;
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