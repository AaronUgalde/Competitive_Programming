#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int testcase){
    int n; ll m; cin >> n >> m;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    ll sum = accumulate(A.begin(), A.end(), 0LL);
    if(sum <= m){
        cout << "infinite" << '\n';
        return;
    }

    int ok = 0, ng = 1e9;
    while(abs(ok - ng) > 1){
        int mid = (ok + ng) >> 1;
        ll temp = 0;
        for(auto &a : A) temp += min(a, mid);
        if(temp <= m){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    cout << ok << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}