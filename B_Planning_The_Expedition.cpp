#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<int> A(m);
    map<int, int> bucket;
    for(auto &a : A) cin >> a, bucket[a]++;
    
    int days = 1;
    for(; days <= m; days++){
        int cnt = 0;
        for(auto &[key, frec] : bucket){
            cnt += frec / days;
        }
        if(cnt < n) break;
    }

    cout << days - 1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}