#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    ll sum_a = 0, sum_b = 0;
    ll n_a = (n + 1) / 2, n_b = n / 2;

    for(int i = 0; i < n; i++){
        if(i % 2 == 0) sum_a += A[i];
        else sum_b += A[i];
    }

    if(sum_a % n_a == 0 and sum_b % n_b == 0 and sum_a / n_a == sum_b / n_b) cout << "YES";
    else cout << "NO";
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}