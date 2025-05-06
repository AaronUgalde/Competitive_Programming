#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    vector<int> b(m);
    for(auto &x : b) cin >> x;
    auto b_copy = b; 

    sort(all(a));
    sort(all(b));
    map<int, int> ans;
    int cnt = 0, a_i = 0, b_i = 0;
    while(a_i < a.size() && b_i < b.size()){
        if(a[a_i] <= b[b_i]){
            cnt++;
            a_i++;
        }else{
            if(b_i < b.size()) ans[b[b_i]] = cnt;
            b_i++;
        }
    }
    while(b_i < b.size()){
        ans[b[b_i]] = cnt;
        b_i++;
    }

    for(int i = 0; i<m; i++){
        cout << ans[b_copy[i]] << " \n"[i+1 == m];
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}