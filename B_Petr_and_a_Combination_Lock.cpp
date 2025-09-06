#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

int mod(int x, int y){
    if(x >= 0) return x % y;
    return y - (x % y);
}

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    for(int mask = 0; mask < (1 << n); mask++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)) sum = mod(sum + A[i], 360);
            else sum = mod(sum - A[i], 360);
        }

        if(sum == 0){
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}