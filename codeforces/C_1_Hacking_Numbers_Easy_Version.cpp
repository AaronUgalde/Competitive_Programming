#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int send_cmd(const string &cmd) {
    cout << cmd << endl;
    cout.flush();
    int res;
    if (!(cin >> res) || res == -1) {
        exit(0);
    }
    return res;
}

int add_cmd(ll y) {
    return send_cmd("add " + to_string(y));
}

int mul_cmd(ll y) {
    return send_cmd("mul " + to_string(y));
}

int div_cmd(ll y) {
    return send_cmd("div " + to_string(y));
}

int digit_cmd() {
    return send_cmd("digit");
}

int answer() {
    return send_cmd("!");
}


void solve(int testcase){
    ll n; cin >> n;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}