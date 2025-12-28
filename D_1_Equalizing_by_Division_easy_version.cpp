#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, k; cin >> n >> k;
    vector<int> A(n);
    for(auto &a : A) cin >> a;
    sort(all(A));

    map<int, vector<int>> num_steps;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        while(A[i] > 0){
            num_steps[A[i]].push_back(cnt);
            A[i] /= 2;
            cnt++;
        }
        num_steps[A[i]].push_back(cnt);
    }

    int ans = INT_MAX;
    for(auto &[key, vec] : num_steps){
        if(sz(vec) >= k) 
            ans = min(ans, accumulate(vec.begin(), vec.begin() + k, 0));
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