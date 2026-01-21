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
    vector<int> A(n), B(n);
    for(auto &a : A) cin >> a; 
    for(auto &b : B) cin >> b;

    ll total_a = accumulate(all(A), 0ll);
    ll total_b = accumulate(all(B), 0ll);

    sort(all(B));

    if(B[n - 1] + B[n - 2] >= total_a){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}