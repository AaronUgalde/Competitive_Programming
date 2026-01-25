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
    vector<ll> B(n + 2);
    map<ll, ll> bucket;
    for(auto &b : B) cin >> b, bucket[b]++;

    ll sum = accumulate(all(B), 0ll);
    for(int i = 0; i < n + 2; i++){
        ll curr_sum = sum - B[i];
        if(
            B[i] < curr_sum and
            bucket[curr_sum - B[i]] >= 1 and
            (
                B[i] != (curr_sum - B[i]) or
                bucket[curr_sum - B[i]] >= 2
            )
        ){
            bucket[B[i]]--;
            bucket[curr_sum - B[i]]--;
            for(auto &[key, frec] : bucket){
                for(int j = 0; j < frec; j++){
                    cout << key << ' ';
                }
            }
            cout << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}