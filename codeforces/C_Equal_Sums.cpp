#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    ll k; cin >> k;
    vector<vector<ll>> sqs(k);
    for(int i = 0; i<k; i++){
        ll n; cin >> n;
        vector<ll> sq(n);
        for(auto &x : sq) cin >> x;
        sqs[i] = sq;
    }

    map<ll, pair<ll, ll>> sum_sq_idx;
    for(int i = 0; i<k; i++){
        ll sum = accumulate(all(sqs[i]), 0ll);
        for(int j = 0; j<sqs[i].size(); j++){
            if(sum_sq_idx.count(sum - sqs[i][j]) && sum_sq_idx[sum-sqs[i][j]].first != i){
                cout << "YES" << endl;
                cout << i + 1 << ' ' << j + 1<< endl;
                cout << sum_sq_idx[sum - sqs[i][j]].first + 1<< ' ' <<  sum_sq_idx[sum - sqs[i][j]].second + 1<< endl;
                return;
            }else{
                sum_sq_idx[sum - sqs[i][j]] = {i, j};
            }
        }
    }

    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}