#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<string> original(n);
    for(auto &s : original) cin >> s;

    vector<map<char, int>> original_frec(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            original_frec[j][original[i][j]]++;
        }
    }

    vector<string> altered(n - 1);
    for(auto &s : altered) cin >> s;

    vector<map<char, int>> altered_frec(m);
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            altered_frec[j][altered[i][j]]++;
        }
    }

    string missing = "";
    for(int i = 0; i < m; i++){
        for(auto &[c, frec] : original_frec[i]){
            if(altered_frec[i][c] != frec) missing += c;
        }
    }

    cout << missing << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}