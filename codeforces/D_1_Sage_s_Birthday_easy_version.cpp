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
    int j = 0;
    vector<int> ans(n);
    for(int i = 1; i < n; j++, i += 2){
        ans[i] = A[j];
    }

    for(int i = 0; i < n; j++, i += 2){
        ans[i] = A[j];
    }

    cout << (n % 2  == 0 ? n / 2 - 1 : n / 2)<< endl;
    for(auto &a : ans) cout << a << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}