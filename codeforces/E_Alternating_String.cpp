#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;
    if(n % 2 == 0){
        vector<vector<int>> appears(2, vector<int>(26));
        for(int i = 0; i < n; i++){
            appears[i % 2][s[i] - 'a']++;
        }

        vector<int> mx(2);
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 26; j++)
                mx[i] = max(mx[i], appears[i][j]);

        int operations = n;
        for(int i = 0; i < 2; i++) operations -= mx[i];
        cout << operations << endl;
        return;
    }

    vector<vector<int>> suf(2, vector<int>(26));
    vector<vector<int>> pre(2, vector<int>(26));
    for(int i = n - 1; i >= 0; i--){
        suf[i % 2][s[i] - 'a']++;
    }
    int mx_mx_mx_equal = INT_MIN;
    for(int i = 0; i < n; i++){
        suf[i % 2][s[i] - 'a']--;
        int mx_mx_equal = 0;
        for(int j = 0; j < 2; j++){
            int mx_equal = INT_MIN;
            for(int k = 0; k < 26; k++){
                mx_equal = max(mx_equal, pre[j][k] + suf[(j + 1) % 2][k]);
            }
            mx_mx_equal += mx_equal;
        }
        mx_mx_mx_equal = max(mx_mx_mx_equal, mx_mx_equal);
        pre[i % 2][s[i] - 'a']++;
    }

    cout << n - mx_mx_mx_equal << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}