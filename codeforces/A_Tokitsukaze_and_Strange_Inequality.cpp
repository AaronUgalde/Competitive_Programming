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
    vector<int> P(n);
    for(auto &p : P) cin >> p;

    // Build f[c][b], how many numbers are less than P[b], from c + 1 to n - 1, for b from 0 to c - 1
    vector<vector<int>> f(n, vector<int>(n));
    for(int c = 1; c < n; c++){
        for(int b = 0; b < c; b++){
            f[c][b] = f[c - 1][b];
            if(b == c - 1){
                int cnt = 0;
                for(int d = c + 1; d < n; d++){
                    if(P[d] < P[b]) cnt++;
                }
                f[c][b] = cnt;
            }else{
                if(P[c] < P[b]) f[c][b]--;
            }
        }
    }

    // Build suffix[c][b] what is the sum of f[c][j] for every j, from b to c - 1
    vector<vector<int>> suffix(n, vector<int>(n));
    for(int c = 1; c < n; c++){
        for(int b = c - 1; b >= 0; b--){
            suffix[c][b] = suffix[c][b + 1] + f[c][b];
        }
    }

    // the answer will be equal to, for every (a, c) valid, answer += suffix[c][a + 1]
    ll ans = 0;
    for(int a = 0; a < n; a++){
        for(int c = a + 1; c < n; c++){
            if(P[c] < P[a]) continue;
            ans += suffix[c][a + 1];
        }
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