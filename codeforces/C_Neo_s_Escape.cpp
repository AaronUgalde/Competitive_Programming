#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(1);
    A[0] = -1e9;
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        if(x != A.back()) A.push_back(x);
    }
    A.push_back(-1e9);


    int i = 0;
    int ans = 0;
    for(int i = 1; i<sz(A); i++){
        if(A[i] > A[i-1] && A[i] > A[i+1]) ans++;
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}