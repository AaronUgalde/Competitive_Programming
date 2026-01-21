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
    vector<int> A(n);
    map<int, int> bucket;
    for(auto &a : A){
        cin >> a;
        bucket[a]++;
    }

    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++){
        p[i] = p[i - 1] + bucket[i];
    }

    int ans = 1;
    for(int g = 1; g <= n; g++){
        int t = min(n, 4 * g - 1);
        int good = (n - p[t]) + bucket[g] + bucket[2 * g] + bucket[3 * g];
        if(good >= n - k) ans = g;
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}