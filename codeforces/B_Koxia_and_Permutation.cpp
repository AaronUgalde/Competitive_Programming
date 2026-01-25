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
    vector<int> ans(n);

    int mx = n, mn = 1;
    bool put_mx = false;

    if(k == 1){
        for(int i = 1; i <= n; i++){
            cout << i << ' ';
        }
        cout << endl;
        return;
    }

    for(int i = 0, j = 0; i < n; i++, j = (j + 1) % (k - 1)){
        if(j == 0) put_mx = !put_mx;
        if(put_mx){
            ans[i] = mx;
            mx--;
        }else{
            ans[i] = mn;
            mn++;
        }
    }

    for(auto &a : ans) cout << a << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}