#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(k);
    for(auto &x: a) cin >> x;
    vector<int> b(n);
    iota(all(b), 1);

    int leader = 0;
    for(int i = 0; i < k; i++){
        int eliminated = (leader + a[i]) % n;
        cout << b[eliminated] << ' ';
        b.erase(b.begin() + eliminated);
        n--;
        leader = eliminated % n;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}