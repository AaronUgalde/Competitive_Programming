#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, t; cin >> n >> t;
    vector<int> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    int max_b = INT_MIN;
    int idx_b = -1;
    for(int i = 0; i<n; i++){
        if(a[i] + i <= t){
            if(b[i] > max_b){
                max_b = b[i];
                idx_b = i + 1;
            }
        }
    }

    cout << idx_b << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}