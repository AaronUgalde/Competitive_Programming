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
    vector<int> A(n); 
    for(auto &a : A) cin >> a;

    int cnt = 2;

    if(n % 2 != 0){
        cout << cnt + 2 << endl;
        cout << n - 1 << ' ' << n << endl;
        cout << n - 1 << ' ' << n << endl;
        cout << 1 << ' ' << n - 1 << endl;
        cout << 1 << ' ' << n - 1 << endl;
    }else{
        cout << cnt << endl;
        cout << 1 << ' ' << n << endl;
        cout << 1 << ' ' << n << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}