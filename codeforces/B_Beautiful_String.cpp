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

    for(int mask = 0; mask < (1 << n); mask++){
        string p = "";
        string x = "";
        for(int j = 0; j < n; j++){
            if(mask & (1 << j)){
                p += s[j];
            }else{
                x += s[j];
            }
        }

        bool is_non_decreasing = true;
        for(int j = 0; j < sz(p) - 1; j++){
            if(p[j] > p[j + 1]){
                is_non_decreasing = false;
                break;
            }
        }

        bool is_palindrome = true;
        for(int j = 0; j < sz(x) / 2; j++){
            if(x[j] != x[sz(x) - 1 - j]){
                is_palindrome = false;
                break;
            }
        }

        if(is_palindrome and is_non_decreasing){
            cout << sz(p) << endl;
            for(int j = 0; j < n; j++){
                if(mask & (1 << j)){
                    cout << j + 1 << ' ';
                }
            }
            cout << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}