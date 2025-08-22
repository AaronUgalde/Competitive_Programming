#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    ll ans = INT_MIN;
    vector<int> vec_ans(n);
    for(int i = 0; i<n; i++){
        int j = i-1, k = i+1;
        ll floors = A[i];
        int last = A[i];
        vector<int> curr_vec_ans(n);
        curr_vec_ans[i] = A[i];
        while(j >= 0){
            floors += min(last, A[j]);
            last = min(last, A[j]);
            curr_vec_ans[j] = last;
            j--;
        }
        last = A[i];
        while(k < n){
            floors += min(last, A[k]);
            last = min(last, A[k]);
            curr_vec_ans[k] = last;
            k++;
        }
        if(floors >= ans){
            ans = floors;
            for(int i = 0; i<n; i++) vec_ans[i] = curr_vec_ans[i];
        }
        ans = max(ans, floors);
    }

    for(auto &x : vec_ans) cout << x << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}