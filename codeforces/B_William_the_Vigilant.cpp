#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, q; cin >> n >> q;
    string s; cin >> s;

    int replace = 0;
    for(int i = 0; i < n - 2; i++){
        if(s[i] == 'a' and s[i + 1] == 'b' and s[i + 2] == 'c') replace++;
    }


    for(int i = 0; i < q; i++){
        int pos; cin >> pos; pos--;
        char c; cin >> c;
        for(int j = max(0, pos - 2); j <= pos and j < n - 2; j++){
            int k = pos - j;
            if(s[j] == 'a' and s[j + 1] == 'b' and s[j + 2] == 'c' and c != ('a' + k)){
                replace--;
            }
            if((s[j] == 'a' or j == pos) and (s[j + 1] == 'b' or j + 1 == pos) and (s[j + 2] == 'c' or j + 2 == pos) and (s[pos] != 'a' + k) and c == ('a' + k)){
                replace++;         
            }
        }
        cout << replace << endl;
        s[pos] = c;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}