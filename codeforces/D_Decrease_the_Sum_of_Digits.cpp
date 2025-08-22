#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    ll n, s; cin >> n >> s;

    auto sum_digits = [&](ll x){
        ll sum = 0;
        while(x > 0){
            sum += x%10;
            x /= 10;
        }
        return sum;
    };

    ll ten_pow = 1;
    ll moves = 0;
    while(sum_digits(n) > s){
        ll digit = (n / ten_pow) % 10;
        ll add = ten_pow * ((10 - digit) % 10);
        n += add;
        moves += add;
        ten_pow *= 10;
    }

    cout << moves << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}