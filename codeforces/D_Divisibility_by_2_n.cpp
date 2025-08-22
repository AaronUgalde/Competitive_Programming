#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;
    
    vector<int> b(n);
    int max_pow = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0, mask = 1; mask <= A[i]; j++, mask = mask << 1){
            if(mask & A[i]){
                max_pow += j;
                break;
            }
        }
        b[i] = __builtin_ctz(i+1);
    }

    sort(all(b), greater<int>());

    for(int i = 0; i<n; i++){
        if(max_pow >= n){
            cout << i << endl;
            return;
        }
        max_pow += b[i];
    }
    

    cout << -1 << endl;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}