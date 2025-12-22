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
    string s; cin >> s;

    int balance = 0;
    for(auto &c : s){
        balance += (c == 'a' ? 1 : -1);
    }

    if(balance == 0){
        cout << 0 << endl;
        return;
    }

    if(balance < 0){
        for(auto &c : s){
            c = (c == 'a' ? 'b' : 'a');
        }
        balance = -balance;
    }


    map<int, int> balance_position;
    int curr_balance = 0;
    int ans = INT_MAX;
    for(int i = 0; i < sz(s); i++){
        balance_position[curr_balance] = i;
        curr_balance += (s[i] == 'a' ? 1 : -1);
        int balance_needed = curr_balance - balance;
        if(balance_position.count(balance_needed)){
            ans = min(ans, i - balance_position[balance_needed] + 1);
        }
    }

    cout << (ans == n ? -1 : ans) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}