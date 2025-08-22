#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, q; cin >> n >> q;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    int n_zeros = 0, n_ones = 0;
    for(auto &a : A){
        if(a == 0) n_zeros++;
        else n_ones++;
    }

    for(int i = 0; i<q; i++){
        int t, x; cin >> t >> x; x--;
        if(t == 1){
            if(A[x] == 0){
                n_ones++;
                n_zeros--;
                A[x] = 1;
            }else{
                n_ones--;
                n_zeros++;
                A[x] = 0;
            }
        }else{
            cout << (x + 1 <= n_ones ? 1 : 0) << endl;
        }
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