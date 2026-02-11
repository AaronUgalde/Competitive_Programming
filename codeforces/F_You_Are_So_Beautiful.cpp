#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    vector<int> r(n);
    set<int> appeard_r;
    for(int i = n - 1; i >= 0; i--){
        if(!appeard_r.count(A[i])){
            r[i] = 1;
            appeard_r.insert(A[i]);
        }
    }

    int cnt = accumulate(all(r), 0);
    ll ans = 0;

    set<int> appeard_l;
    for(int i = 0; i < n; i++){
        if(!appeard_l.count(A[i])){
            ans += cnt;
            appeard_l.insert(A[i]);
        }
        if(r[i] == 1){
            cnt--;
        }
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