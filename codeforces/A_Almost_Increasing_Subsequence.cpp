#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, q; cin >> n >> q;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    vector<int> pf(n + 1, 0);
    bool down = false;
    pf[1] = 1;
    for(int i = 1; i < n; i++){        
        pf[i + 1] = pf[i];
        if(A[i] <= A[i - 1] and down == false){
            pf[i + 1]++;
            down = true;
        }else if(A[i] > A[i - 1]){
            pf[i + 1]++;
            down = false;
        }
    }

    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        int x = pf[r] - pf[l - 1];
        if(l + 1 <= n and pf[l] == pf[l + 1] and (r - l) > 0) x++;
        if(l - 1 >= 0 and pf[l] == pf[l - 1]) x++;
        cout << x << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}