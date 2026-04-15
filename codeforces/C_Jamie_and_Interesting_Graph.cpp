#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n, m; cin >> n >> m;

    cout << fixed << setprecision(0);

    int prime = -1;
    for(int i = n; prime == -1; i++){
        int c_i = i;
        bool is_prime = true;
        for(int j = 2; j * j <= c_i; j++){
            if(c_i % j == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime) prime = c_i;
    }

    vector<int> one_to_x(n + 1, 1);
    one_to_x[n] = 2;
    one_to_x[2] += (prime - n);

    cout << 2 << ' ' << prime << endl;

    for(int i = 2; i <= n; i++){
        cout << 1 << ' ' << i << ' ' << one_to_x[i] << endl;
    }

    m -= n - 1;

    for(int i = 2; i <= n and m > 0; i++){
        for(int j = i + 1; j <= n and m > 0; j++){
            cout << i << ' ' << j << ' ' << 1e9 << endl;
            m--;
        }
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