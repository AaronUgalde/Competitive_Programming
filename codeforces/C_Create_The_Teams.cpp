#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, x; cin >> n >> x;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    sort(all(A), greater<int>());
    int cnt = 1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(A[i] * cnt >= x){
            ans++;
            cnt = 1;
        }else{
            cnt++;
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