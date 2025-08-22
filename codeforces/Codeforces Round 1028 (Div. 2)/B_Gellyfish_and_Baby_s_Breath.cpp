#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int MOD = 998244353;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(int testcase){
    int n; cin >> n;
    vector<ll> p(n);
    vector<ll> q(n);
    for(auto &x: p) cin >> x;
    for(auto &x: q) cin >> x;

    int idx_mx_p = 0;
    int idx_mx_q = 0;
    vector<ll> r(n);
    for(int i = 0; i<n; i++){
        if(p[i] > p[idx_mx_p]) idx_mx_p = i;
        if(q[i] > q[idx_mx_q]) idx_mx_q = i;
        if(p[idx_mx_p] > q[idx_mx_q]){
            r[i] = binpow(2, p[idx_mx_p], MOD) + binpow(2, q[i-idx_mx_p], MOD);
        }else if(p[idx_mx_p] < q[idx_mx_q]){
            r[i] = binpow(2, q[idx_mx_q], MOD) + binpow(2, p[i-idx_mx_q], MOD);
        }else{
            if(q[i - idx_mx_p] > p[i - idx_mx_q]){
                r[i] = binpow(2, p[idx_mx_p], MOD) + binpow(2, q[i-idx_mx_p], MOD);
            }else if(q[i - idx_mx_p] <= p[i - idx_mx_q]){
                r[i] = binpow(2, q[idx_mx_q], MOD) + binpow(2, p[i-idx_mx_q], MOD);
            }
        }
        r[i] %= MOD;
    }

    for(int i = 0; i<n; i++){
        cout << r[i] << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}