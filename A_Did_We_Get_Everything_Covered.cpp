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

    vector<vector<int>> prefix(k, vector<int>(m + 1, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < k; j++){
            prefix[j][i + 1] += prefix[j][i]; 
        }
        prefix[s[i] - 'a'][i + 1]++;
    }

    vector<vector<int>> cnt(2, vector<int>(k, 0));
    vector<vector<char>> fail(2, vector<char>(k));
    for(int i = 0; i < m; i++){
        for(int l = 0; l < 2; l++){
            int times = cnt[l][s[i] - 'a'];
            bool ok = true;
            for(int j = 0; j < k; j++){
                int total = (k == 0 ? prefix[j][m] - prefix[j][i + 1] : prefix[j][i]);
                int need = (k == 0 ? n - times - 1 : times);
                cout << " char: " << char(i + 'a') << ' ';
                cout << " total: " << total << endl;
                cout << " need: " << need << endl;
                if(total < need){
                    ok = false;
                    fail[l][s[i] - 'a'] = j + 'a';
                    cout << fail[l][s[i] - 'a'] << endl;
                }
            }
            if(ok) cnt[l][s[i] - 'a']++;
        }
    }
        

    for(int i = 0; i < k; i++){
        string cant = "X";
        if(cnt[0][i] < n){
            cant = string(cnt[0][i], char(i + 'a')) + string(n - cnt[0][i], fail[0][i]);
        }else if(cnt[1][i] < n){
            cant = string(cnt[1][i], fail[1][i]) + string(n - cnt[1][i], char(i + 'a'));
        }
        if(cant != "X"){
            cout << "NO" << endl;
            cout << cant << endl;
            return;
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