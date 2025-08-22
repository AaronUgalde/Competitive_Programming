#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    int idx_first = -1, idx_last = -1;
    for(int i = 0; i<n-1; i++){
        if(A[i] == A[i+1]){
            if(idx_first == -1){
                idx_first = i;
            }else{
                idx_last = i;
            }
        }
    }

    if(idx_last != -1){
        if(idx_last - idx_first == 1) cout << 1 << endl;
        else cout << idx_last - idx_first - 1 << endl;
    }else{
        cout << 0 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}