#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int N; cin >> N;
    vector<int> L(N);
    for(auto &l : L) cin >> l;

    int balance = 1;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(L[i] >= balance) cnt++;
        balance = abs(L[i] - balance);
    }

    cout << cnt << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}