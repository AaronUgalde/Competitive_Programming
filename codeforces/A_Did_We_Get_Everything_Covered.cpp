#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, k, m; cin >> n >> k >> m;
    string s; cin >> s;

    bitset<26> group;
    string res = "";
    for(int i = 0; i < m; i++){
        group[s[i] - 'a'] = 1;
        if(group.count() == k){
            res += s[i];
            group.reset();
        }
    }

    if(sz(res) < n){
        char repeat;
        for(int i = 0; i < k; i++){
            if(group[i] == 0) repeat = i + 'a';
        }
        cout << "NO" << endl << res + string(n - sz(res), repeat) << endl;
        return;
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