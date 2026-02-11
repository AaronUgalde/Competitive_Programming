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
    vector<int> A(n + 2);
    A[0] = 0;
    A[n + 1] = 1001;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }

    int ans = INT_MIN;
    int curr = 0;
    for(int i = 1; i <= n + 1; i++){
        if(A[i] == A[i - 1] + 1){
            curr++;
        }else{
            ans = max(ans, curr - 1);
            curr = 0;
        }
    }
    ans = max(ans, curr - 1);

    cout << max(0, ans) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}