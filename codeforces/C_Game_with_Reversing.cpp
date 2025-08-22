#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

int make_equal(string s, string t){
    int diff = 0;
    for(int i = 0; i<sz(s); i++){
        if(s[i] != t[i]) diff++;
    }
    return diff;
}

void solve(int testcase){
    int n; cin >> n;
    string s, t; cin >> s >> t;

    string rs = s; reverse(all(rs));
    string rt = t; reverse(all(rt));
    int t_equal_s = make_equal(s, t);
    t_equal_s = t_equal_s * 2 - (t_equal_s % 2 != 0);
    int t_equal_rs = make_equal(rs, t);
    t_equal_rs += t_equal_rs * 2 - (t_equal_rs % 2 == 0);
    if(t_equal_rs == -1) t_equal_rs = 2;
    int rt_equal_s = make_equal(s, rt);
    rt_equal_s = rt_equal_s * 2 - (rt_equal_s % 2 == 0);
    if(rt_equal_s == -1) rt_equal_s = 2;
    int turns = min(min(t_equal_s, t_equal_rs), rt_equal_s);
    cout << turns << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}