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

    for(int i = 1; i < n - 1; i++){
        if(A[i] == -1) A[i] = 0;
    }

    int mx = max(A[0], A[n - 1]);
    if(A[0] == -1 or A[n - 1] == -1) A[0] = A[n - 1] = mx;
    if(A[0] == -1){
        A[0] = A[n - 1] = 0;
    }

    cout << abs(A[0] - A[n - 1]) << endl;
    for(auto &a : A) cout << a << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}