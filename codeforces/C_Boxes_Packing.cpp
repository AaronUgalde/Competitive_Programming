#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;
    sort(all(A));

    map<int, int> bucket;
    for(auto &a : A){
        bucket[a]++;
    }

    int ans = 0;
    for(auto &[key, frec] : bucket){
        ans = max(ans, frec);
    }

    cout << ans << endl;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}