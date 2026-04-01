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

    if(n == 1){
        cout << 1 << ' ' << 0 << endl;
        return;
    }

    map<int, int> prime_count;
    for(int i = 2; i * i <= n; i++){
        if(n % i != 0) continue;
        int cnt = 0;
        while(n % i == 0){
            n /= i;
            cnt++;
        }
        prime_count[i] = cnt;
    }

    if(n > 1){
        prime_count[n]++;
    }

    int mx = INT_MIN;
    int ans = 1;
    for(auto &[prime, count] : prime_count){
        ans *= prime;
        mx = max(mx, count);
    }

    int pot2 = (__builtin_popcount(mx) == 1 ? mx : (1 << (32 - __builtin_clz(mx))));

    bool all_equal = (pot2 == mx ? true : false);

    for(auto &[prime, count] : prime_count){
        if(count != pot2){
            all_equal = false;
            break;
        }
    }

    cout << ans << ' ' << (31 - __builtin_clz(pot2)) + (all_equal ? 0 : 1) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    for(int i = 0; i<t; i++){
        solve();
    }
}