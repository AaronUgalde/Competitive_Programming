#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n; cin >> n;
    vector<int> T(n + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> T[i + 1];
    }

    vector<int> memo(n + 1, 0);
    int b_i = 0, c_i = 0;
    int min_used_b = 0, min_used_c = 0;
    for(int i = 1; i <= n; i++){
        min_used_b = T[i];
        min_used_c = T[i];
        while(b_i < n and min_used_b - T[b_i] > 90){
            b_i++;
        }
        min_used_b -= T[b_i];
        while(c_i < n and min_used_c - T[c_i] > 90){
            c_i++;
        }
        min_used_c -= T[c_i];
        int a = 20 + memo[i - 1];
        int b = (min_used_b <= 90 ? 50 + memo[b_i] : INT_MAX);
        int c = (min_used_c <= 90 ? 1440 + memo[c_i] : INT_MAX);
        memo[i] = min({a, b, c});
        cout << "memo[i]: " << memo[i] << endl;
        cout << "T[i]: " << T[i] << endl;
        cout << "b_i: " << b_i << " min_used_b: " << min_used_b << endl;
        cout << "c_i: " << c_i << " min_used_c: " << min_used_c << endl;
        cout << memo[i] - memo[i - 1] << endl;
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