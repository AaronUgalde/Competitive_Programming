#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; 
    if(!(cin >> n)) return;
    vector<int> A(n), B(n);
    int x = 0;
    for(int i = 0; i < n; ++i){ cin >> A[i]; x ^= A[i]; }
    for(int i = 0; i < n; ++i){ cin >> B[i]; x ^= B[i]; }

    if(x == 0){
        cout << "Tie\n";
        return;
    }

    int mx_i = -1;
    for(int i = 31; i >= 0; --i){
        if( (x >> i) & 1 ){
            mx_i = i;
            break;
        }
    }

    for(int i = n-1; i >= 0; --i){
        if( ((A[i] ^ B[i]) >> mx_i) & 1 ){
            cout << ( (i % 2 == 0) ? "Ajisai\n" : "Mai\n");
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