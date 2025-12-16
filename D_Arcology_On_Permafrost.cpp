#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, m, k;
    cin >> n >> m >> k;
    int res = max(0, n - (m + 1) * k);
    int tam = k + res / (m + 1);
    vector<int> A(k + res / (m + 1));
    iota(all(A), 0);

    for(int i = 0; i < n; i++){
        cout << A[i % tam] << ' ';
    }

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