#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> L(k);
    vector<int> R(k);
    for(auto &l : L) cin >> l, l--;
    for(auto &r : R) cin >> r, r--;

    int q; cin >> q;
    vector<int> X(q);
    for(auto &x : X) cin >> x, x--;

    vector<int> is_reversed(n, 0);
    for(auto &x : X){
        is_reversed[x]++;
    }

    for(int i = 0; i < k; i++){
        int sum = 0;
        for(int j = L[i]; j <= (L[i] + R[i]) / 2; j++){
            sum += is_reversed[j] + is_reversed[R[i] + L[i] - j];
            if(sum & 1) swap(s[j], s[R[i] + L[i] - j]);
        }
    }

    cout << s << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}