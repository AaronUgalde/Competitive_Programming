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

    bool is_sorted = true;
    for(int i = 0; i < n; i++){
        if(A[i] != i + 1){
            is_sorted = false;
            break;
        }
    }

    if(is_sorted){
        cout << 0 << endl;
    }else if(A[0] == 1 or A[n - 1] == n){
        cout << 1 << endl;
    }else if(A[0] != n or A[n - 1] != 1){
        cout << 2 << endl;
    }else{
        cout << 3 << endl;
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