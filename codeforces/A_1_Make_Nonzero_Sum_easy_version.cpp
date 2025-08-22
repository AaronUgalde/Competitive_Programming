#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    if(sz(A) % 2 != 0){
        cout << -1 << endl;
        return;
    }

    vector<pair<int, int>> ans;
    for(int i = 0; i<n; i+=2){
        if(A[i] == A[i+1]){
            ans.emplace_back(i+1, i+2);
        }else{
            ans.emplace_back(i+1, i+1);
            ans.emplace_back(i+2, i+2);
        }
    }

    cout << sz(ans) << endl;
    for(auto &[l, r] : ans){
        cout << l << ' ' << r << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}