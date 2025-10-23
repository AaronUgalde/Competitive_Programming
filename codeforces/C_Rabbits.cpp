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

    int n_zeros = 0;
    bool start = false;
    for(int i = 1; i < n - 1; i++){
        if(s[i] == '1') continue;
        if(s[i - 1] == '1' and (i == 1 or s[i - 2] == '1')){
            start = true;
            n_zeros = 1;
        }
        if(!start or s[i + 1] != '1' or s[i - 1] != '1'){
            start = false;
            continue;
        }
        if(i == n - 2 or s[i + 2] == '1'){
            if(n_zeros % 2 != 0){
                cout << "NO" << endl;
                return;
            }
            start = false;
        }else if(s[i - 1] == '1'){
            n_zeros++;
        }else{
            start = false;
        }
    }

    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}