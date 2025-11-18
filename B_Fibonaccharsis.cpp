#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

struct fib{
    ll x;
    ll y; 
    fib operator+(const fib &b){
        return fib{x + b.x, y + b.y};
    }
};

void solve(int testcase){
    int n, k; cin >> n >> k;

    if(n == 0){
        cout << 1 << endl;
        return;
    }

    if(k >= 7 and k > n){
        cout << 0 << endl;
        return;
    }

    fib first = {1, 0};
    fib second = {0, 1};
    for(int i = 3; i <= k; i++){
        fib t = first + second;
        first = second;
        second = t;
        if(second.x > n){
            cout << 0 << endl;
            return;
        }
    }

    int cnt = 0;
    for(int i = 0; i <= n; i++){
        int a = n - second.y * i;
        int j = a / second.x;
        if(a % second.x == 0 and j >= 0 and j <= i){
            cnt++;
        }
    }

    cout << cnt << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}