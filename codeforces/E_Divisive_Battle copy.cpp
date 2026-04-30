#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

vector<vector<int>> sieve(){
    vector<int> is_prime(1e6 + 1, 1);
    vector<int> primes;
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 2; i <= 1e6; i++){
        if(!is_prime[i]) continue;
        primes.push_back(i);
        for(int j = 2 * i; j <= 1e6; j += i) is_prime[j] = 0;
    }
    vector<vector<int>> ans(2);
    ans[0] = primes;
    ans[1] = is_prime;
    return {primes, is_prime};
}

void solve(vector<int> &primes, vector<int> &is_prime){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    vector<int> first_prime(n, -1);

    bool is_sorted = true; 
    for(int i = 0; i < n - 1; i++){
        if(A[i] > A[i + 1]){
            is_sorted = false;
            break;
        }
    }

    if(is_sorted){
        cout << "Bob" << endl;
        return;
    }

    for(int i = 0; i < n; i++){
        int cnt = 0;
        if(is_prime[A[i]] == 1){
            first_prime[i] = A[i];
            continue;
        }
        int x = A[i];
        for(int j = 0; primes[j] * primes[j] <= A[i]; j++){
            if(A[i] % primes[j] == 0){
                if(first_prime[i] == -1) first_prime[i] = primes[j];
                
                cnt++;
                while(x % primes[j] == 0)
                    x /= primes[j];

            }
        }

        if(x > 1){
            if(first_prime[i] == -1)
                first_prime[i] = x;
            cnt++;
        }

        if(cnt == 2){
            cout << "Alice" << endl;
            return;
        }
    }

    for(int i = 0; i < n - 1; i++){
        if(first_prime[i] > first_prime[i + 1]){
            cout << "Alice" << endl;
            return;
        }
    }

    cout << "Bob" << endl;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;

    vector<vector<int>> ans = sieve();
    vector<int> primes = ans[0];
    vector<int> is_prime = ans[1];

    for(int i = 0; i<t; i++){
        solve(primes, is_prime);
    }
}