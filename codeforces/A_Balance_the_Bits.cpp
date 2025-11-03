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
    
    int n_ones = 0;
    for(auto &c : s){
        if(c == '1') n_ones++;
    }

    if(n_ones % 2 != 0 or s[0] != '1' or s[n - 1] != '1'){
        cout << "NO" << endl;
        return;
    }

    string a, b;
    int ones_used = 0, zeros_used = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            if(ones_used < n_ones / 2){
                a += '(';
                b += '(';
            }else{
                a += ')';
                b += ')';
            }
            ones_used++;
        }else{
            if(zeros_used % 2 == 0){
                a += '(';
                b += ')';
            }else{
                b += '(';
                a += ')';
            }
            zeros_used++;
        }
    }

    cout << "YES" << endl;
    cout << a << endl << b << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}