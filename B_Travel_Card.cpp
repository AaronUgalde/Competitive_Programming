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
    vector<int> T(n);
    for(auto &t : T) cin >> t;

    vector<int> memo(n + 1, 0);
    for(int i = 1; i <= n; i++){
        min_used_b += T[i - 1]
        min_used_c += T[i - 1]
        while(min_used_b > 90){
            min_used_b -= T[j]
            j++;
        }
        while(min_used_c > 90){
            min_used_c -= T[k]
            k++;
        }

        int a = 20 + memo[i - 1];
        int b = 50 + memo[j];
        int c = 1440 + memo[k];
        memo[i] = min(a, b, c);
        cout << memo[i] << endl;
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