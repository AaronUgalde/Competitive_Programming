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
    int x = 0;
    vector<int> A(n);
    for(auto &a : A) cin >> a, x ^= a;
    vector<int> B(n);
    for(auto &b : B) cin >> b, x ^= b;

    if(x == 0){
        cout << "Tie" << endl;
        return;
    }

    for(int i = n - 1; i >= 0; i--){
        if(A[i] != B[i]){
            cout << (i % 2 == 0 ? "Ajisai" : "Mai") << endl;
            return;
        }
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