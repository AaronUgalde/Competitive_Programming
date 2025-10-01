#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(2 * n);
    for(auto &a : A) cin >> a;

    int ans = 0;
    for(int i = 0; i < 2 * n; i += 2){
        for(int j = i + 1; j < 2 * n; j++){
            if(A[j] == A[i]){
                rotate(A.begin() + i + 1, A.begin() + j, A.begin() + j + 1);
                ans += j - i - 1;
            }
        }
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