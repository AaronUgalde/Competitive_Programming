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
    
    sort(all(A));
    int x = A[n - 1];
    for(int i = n - 2; i >= 0; i--){
        if(x % A[i] != 0 or A[i] == A[i + 1]){
            cout << x << ' ' << A[i] << endl;
            return;
        }       
    }

    cout << x << ' ' << 1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}