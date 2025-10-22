#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cout << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, k, l, r;
    if (!(cin >> n >> k >> l >> r)) return;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];

    map<int,int> freqK;    
    map<int,int> freqKm1;  

    int r1 = 0; 
    int r2 = 0; 
    int distinctK = 0, distinctKm1 = 0;
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        while (r1 < n) {
            int v = A[r1];
            if (freqK[v] == 0 && distinctK == k) break;
            if (freqK[v] == 0) ++distinctK;
            ++freqK[v];
            ++r1;
        }


        while (r2 < n) {
            int v = A[r2];
            if (freqKm1[v] == 0 && distinctKm1 == k - 1) break;
            if (freqKm1[v] == 0) ++distinctKm1;
            ++freqKm1[v];
            ++r2;
        }

        ans += max(0, min(r1 - 1, i + r - 1) - max(r2, i + l - 1) + 1);

        int vi = A[i];

        freqK[vi]--;
        if(freqK[vi] == 0) distinctK--;

        freqKm1[vi]--;
        if(freqKm1[vi] == 0) distinctKm1--;
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}