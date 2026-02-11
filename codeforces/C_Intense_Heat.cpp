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
    vector<double> A(n);
    for(auto &a : A) cin >> a;

    double mx = INT_MIN;
    for(int i = 0; i < n; i++){
        double curr = 0;
        for(int j = i; j < n; j++){
            curr += A[j];
            if(j - i + 1 >= k) mx = max(mx, curr / (j - i + 1));
        }
    }

    cout << setprecision(15) << fixed << mx << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}