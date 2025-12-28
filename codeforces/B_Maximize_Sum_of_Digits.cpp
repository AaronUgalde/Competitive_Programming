#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    string s; cin >> s;

    auto digitsum = [&](string &y){
        int sum = 0;
        for(int i = 0; i < sz(y); i++){
            sum += y[i] - '0';
        }
        return sum;
    };

    int mx = digitsum(s);
    string mx_s = s;

    for(int i = 1; i < sz(s); i++){
        string x = s.substr(0, i - 1) + char(s[i - 1] - 1) + string(sz(s) - i, '9');
        if(digitsum(x) > mx or (digitsum(x) == mx and stoll(x) >= stoll(mx_s))){
            mx_s = x;
            mx = digitsum(x);
        }
    }

    cout << stoll(mx_s) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}