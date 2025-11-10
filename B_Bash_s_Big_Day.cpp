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
    vector<int> S(n);
    for(auto &s : S) cin >> s;

    vector<int> primes;
    const int MAX_N = 1e5 + 3;  
    auto sieve = [&](){
        vector<bool> is_prime(MAX_N + 1, true);
        for(ll i = 2; 1ll * i * i <= MAX_N; i++){
            if(is_prime[i]){
                primes.push_back(i);
                for(int j = i * i; j <= MAX_N; j += i){
                    is_prime[j] = false;
                }
            }
        }
    };
    
    sieve();

    map<int, int> prime_cnt;
    for(auto &s : S){
        for(auto &p: primes){
            if(s % p == 0) {
                prime_cnt[p]++;
                while(s % p == 0) s /= p;
            }
        }

        if(s > 1){
            prime_cnt[s]++;
        }
    }

    int ans = 1;
    for(auto &[prime, cnt]  : prime_cnt){
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}