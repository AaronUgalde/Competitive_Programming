#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    string s; cin >> s;
    
    map<char, int> last_seen;
    for(auto &c : s){
        last_seen[c] = -1;
    }

    map<char, int> max_seg;
    for(auto &c : s){
        max_seg[c] = INT_MIN;
    }

    for(int i = 0; i<sz(s); i++){
        max_seg[s[i]] = max(max_seg[s[i]], i - last_seen[s[i]] - 1);
        last_seen[s[i]] = i;
    }

    int min_max_seg = INT_MAX;
    for(auto &[c, seg] : max_seg){
        seg = max(seg, sz(s) - last_seen[c] - 1);
        min_max_seg = min(min_max_seg, seg);
    }

    int ans = 0;
    while(min_max_seg > 0){
        min_max_seg /= 2;
        ans++;
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