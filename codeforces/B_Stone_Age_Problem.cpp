#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, q; cin >> n >> q;
    vector<ll> A(n); 
    for(auto &a : A) cin >> a;

    vector<int> id(n, 0);
    int curr_id = -1;
    ll curr_x = -1;
    ll curr_sum = accumulate(all(A), 0ll);
    for(int i = 0; i<q; i++){
        int t; cin >> t;
        if(t == 1){
            ll i, x; cin >> i >> x; i--;
            if(id[i] > curr_id){
                curr_sum = curr_sum - A[i] + x;
            }else{
                curr_sum = curr_sum - curr_x + x;
                id[i] = curr_id + 1;
            }
            A[i] = x;
        }else{
            ll x; cin >> x;
            curr_sum = x*n;
            curr_x = x;
            curr_id++;
        }
        cout << curr_sum << endl;
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