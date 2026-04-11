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

    int sq = sqrt(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(A[i] <= sq){
            for(int k = 1; k <= sq and i + k * A[i] < n; k++){
                if(A[i + k * A[i]] == k) ans++;
            }
        }else{
            for(int k = 1; i + k * A[i] < n or i - k * A[i] >= 0; k++){
                if(i + k * A[i] < n and A[i + k * A[i]] == k) ans++;
                if(i - k * A[i] >= 0 and A[i - k * A[i]] == k) ans++;
            }
        }
    }

    cout << ans << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}