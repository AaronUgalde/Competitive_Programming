#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;
const ll MAX_N = 1e12 + 2;
vector<int> sumOfDivisors(MAX_N, 0);

void solve(int testcase){
    ll n; cin >> n;
    ll ans = 0;
    for(int i = 0; i <= n; i++){
        ans = (ans + sumOfDivisors[i]) % MOD;
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    for(int i = 1; i < MAX_N; i++){
        for(int j = i; j < MAX_N; j += i){
            sumOfDivisors[j] += i;
        }
    }

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}