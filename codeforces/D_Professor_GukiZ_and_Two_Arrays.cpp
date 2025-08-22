#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

pair<int, int> best_op(vector<ll> &A, vector<ll> &B, ll &s_a, ll &s_b){
    pair<int, int> best;
    for(int i = 0; i<A.size(); i++){
        for(int j = 0; j<B.size(); j++){
            if(abs(s_a - A[i] + B[j] - (s_b - B[j] + A[i])) < abs(s_a - A[best.first] + B[best.second] - (s_b - B[best.second] + A[best.first]))){
                best = {i, j};
            }
        }
    }
}

void solve(int testcase){
    int n; cin >> n;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;
    int m; cin >> m;
    vector<ll> B(m);
    for(auto &b : B) cin >> b;

    ll s_a = accumulate(all(A), 0ll);
    ll s_b= accumulate(all(B), 0ll);
    ll v = abs(s_a - s_b);

    pair<int, int> op1 = best_op(A, B, s_a, s_b);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}