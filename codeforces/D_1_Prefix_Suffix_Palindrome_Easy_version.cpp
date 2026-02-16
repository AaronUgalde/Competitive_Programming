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
    int n = sz(s);

    int i = 0, j = n - 1;
    while(i < j and s[i] == s[j]){
        i++;
        j--;
    }
    string x = s.substr(i, j - i + 1);
    int m = sz(x);

    string first = "";
    for(int i = 0; i <= m; i++){
        string y = x.substr(0, i);
        bool is_pal = true;
        for(int j = 0; j < sz(y) / 2; j++){
            if(y[j] != y[sz(y) - 1 - j]){
                is_pal = false;
                break;
            }
        }

        if(is_pal){
            first = y;
        }
    }

    string last = "";
    for(int i = m - 1; i >= 0; i--){
        string y = x.substr(i);
        bool is_pal = true;
        for(int j = 0; j < sz(y) / 2; j++){
            if(y[j] != y[sz(y) - 1 - j]){
                is_pal = false;
                break;
            }
        }

        if(is_pal){
            last = y;
        }
    }

    string ans = (sz(first) > sz(last) ? first : last);

    cout << s.substr(0, i) + ans + s.substr(j + 1) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}