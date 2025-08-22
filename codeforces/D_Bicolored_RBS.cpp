#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;
    stack<int> colors;
    bool red = true;

    vector<int> ans(n);
    for(int i = 0; i<n; i++){
        if(s[i] == '('){
            colors.push(colors.size() % 2);
            ans[i] = colors.top();
        }else{
            if(colors.top() == 1) ans[i] = 1;
            else ans[i] = 0;
            colors.pop();
        }
    }

    for(auto &a : ans) cout << a;
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}