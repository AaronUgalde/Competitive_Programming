#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2e5;
vector<vector<int>> memo(MAXN, vector<int>(3, 0));

int mod(int a, int b){
    ll r = a % b;
    if(r < 0) r += b;
    return r;
}

void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;

    memo[0][0] = s[0] == 'S' ? 1 : 0;
    memo[0][1] = s[0] == 'P' ? 1 : 0;
    memo[0][2] = s[0] == 'R' ? 1 : 0;

    vector<int> mods(n);
    for(int i = 0; i<n; i++)
        if(s[i] == 'R') mods[i] = 0;
        else if(s[i] == 'S') mods[i] = 1;
        else if(s[i] == 'P') mods[i] = 2;

    for(int i = 1; i<n; i++){
        memo[i][mods[i]] = max(memo[i - 1][mod(mods[i] + 1, 3)], memo[i - 1][mod(mods[i] - 1, 3)]);
        memo[i][mod(mods[i] - 1, 3)] = max(memo[i - 1][mod(mods[i], 3)], memo[i - 1][mod(mods[i] - 2, 3)]) + 1;
    }


    cout << max(memo[n - 1][2], max(memo[n - 1][0], memo[n - 1][1])) << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}