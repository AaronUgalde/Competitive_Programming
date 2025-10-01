#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    map<char, int> bucket;
    for(int i = 0; i < n; i++){
        bucket[s[i]]++;
    }

    int diff = 'A' - 'a';
    int ans = 0;
    for(auto &[key, frec] : bucket){
        int sum = (isupper(key) ? -diff : diff);
        int mn = min(frec, bucket[key + sum]);
        int mx = max(frec, bucket[key + sum]);
        ans += mn + min(k, (mx - mn) / 2);
        k = max(0, k - (mx - mn)/2);
        frec = 0;
        bucket[key + sum] = 0;
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}