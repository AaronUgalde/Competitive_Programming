#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    ll n, m; cin >> n >> m;
    ll bits_available = min(1ll * 21, (m * 8) / n);
    ll K = (1 << bits_available);

    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    sort(all(A));
    
    ll distinct = 0;
    ll best = n;
    map<ll, ll> frec; 
    for(int i = 0, j = 0; i < n; i++){
        while(j < n && (distinct < K || frec.count(A[j]))){
            if(frec[A[j]]++ == 0) distinct++;
            j++;
        }

        best = min(best, i + n - j);
        if(--frec[A[i]] == 0) distinct--;
    }

    cout << best << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}