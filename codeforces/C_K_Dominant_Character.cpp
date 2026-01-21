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
    
    vector<int> last_saw('z' - 'a' + 1, -1);
    vector<int> max_dis('z' - 'a' + 1, INT_MIN);
    for(int i = 0; i < sz(s); i++){
        max_dis[s[i] - 'a'] = max(i - last_saw[s[i] - 'a'], max_dis[s[i] - 'a']);
        last_saw[s[i] - 'a'] = i;
    }

    int min_dis = INT_MAX;
    for(int i = 0; i <= ('z' - 'a'); i++){
        max_dis[i] = max(sz(s) - last_saw[i], max_dis[i]);
        min_dis = min(min_dis, max_dis[i]);
    }

    cout << min_dis << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}