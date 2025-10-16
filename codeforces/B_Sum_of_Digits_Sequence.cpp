#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int N; cin >> N;
    ll sum = 0;

    auto f = [&](int x){
        if(x == 0) return 1;
        int res = 0;
        string s_x = to_string(x);
        for(int i = 0; i < sz(s_x); i++){
            res += s_x[i] - '0';
        }
        return res;
    };

    for(int i = 0; i < N; i++){
        sum += f(sum);
    }

    cout << sum << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}