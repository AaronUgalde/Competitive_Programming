#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n), B(n);
    for(auto &a : A) cin >> a;
    for(auto &b : B) cin >> b;

    int a_g_b = 0;
    int b_g_a = 0;
    for(int i = 0; i<n; i++){
        if(A[i] > B[i]) a_g_b += A[i] - B[i];
        else b_g_a += B[i] - A[i];
    }

    cout << a_g_b + 1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}