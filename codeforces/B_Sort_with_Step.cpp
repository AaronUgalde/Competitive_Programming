#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, k; cin >> n >> k;
    vector<int> P(n);
    for(auto &p : P) cin >> p;

    int cnt_bad = 0;
    for(int i = 0; i < n; i++){
        if(i % k != (P[i] - 1) % k) cnt_bad++;
    }

    cout << (cnt_bad == 0 ? 0 : cnt_bad == 2 ? 1 : -1) << endl; 
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}