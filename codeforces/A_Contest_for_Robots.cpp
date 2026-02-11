#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    vector<int> R(n), B(n);
    for(auto &r : R) cin >> r;
    for(auto &b : B) cin >> b;

    int cnt_r = 0, cnt_b = 0;
    for(int i = 0; i < n; i++){
        if(R[i] == 1 and B[i] == 0) cnt_r++;
        else if(R[i] == 0 and B[i] == 1) cnt_b++;
    }

    if(cnt_r == 0){
        cout << -1 << endl;
        return;
    }

    if(cnt_r > cnt_b){
        cout << 1 << endl;
        return;
    }

    cout << cnt_b / cnt_r + 1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}