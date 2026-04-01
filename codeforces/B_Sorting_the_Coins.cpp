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
    vector<int> A(n, 0);

    int ans = 1;
    int j = n - 1;
    cout << 1 << ' ';
    for(int i = 0; i < n; i++){
        int p; cin >> p, p--;
        A[p] = 1;
        ans++;
        while(A[j] == 1 and j >= 0){
            ans--;
            j--;
        }
        cout << ans << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}