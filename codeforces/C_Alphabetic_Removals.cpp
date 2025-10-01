#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    map<char, int> char_times;
    for(auto &c : s) char_times[c]++;

    map<char, int> remove_char_times;
    int removed = 0;
    for(auto &[c, times] : char_times){
        if(removed < k){
            remove_char_times[c] = min(times, k - removed);
            removed += remove_char_times[c];
        }
    }

    string ans = "";
    for(int i = 0; i < n; i++){
        if(remove_char_times.count(s[i]) && remove_char_times[s[i]] > 0){
            remove_char_times[s[i]]--;
        }else{
            ans += s[i];
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}