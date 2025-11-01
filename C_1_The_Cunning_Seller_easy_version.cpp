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
    ll sum = 0;
    int cnt = 0;
    while(n > 0){
        int res = n % 3;
        n /= 3;
        ll deal = pow(3, cnt + 1) + cnt * pow(3, cnt - 1);
        sum += deal * res;
        cnt++;
    }

    cout << sum << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}