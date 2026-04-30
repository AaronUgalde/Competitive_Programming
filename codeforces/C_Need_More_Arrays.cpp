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

    int j = 0;
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(A[j] + 1 < A[i]){
            ans++;
            j = i;
        }
    }

    cout << ans + 1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}