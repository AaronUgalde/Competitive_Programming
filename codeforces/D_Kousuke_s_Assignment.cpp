#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    vector<ll> prefix_sum(n+1, 0);
    for(int i = 1; i<=n; i++){
        prefix_sum[i] = prefix_sum[i-1] + A[i-1];
    }

    set<ll> appeard;
    int ans = 0;
    for(int i = 0; i<=n; i++){
        if(appeard.contains(prefix_sum[i])){
            ans++;
            appeard.clear();
        }
        appeard.insert(prefix_sum[i]);
    }

    println("{}", ans);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}