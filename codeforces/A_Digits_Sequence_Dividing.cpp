#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;
    if(n > 2){
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << s.substr(0, 1) << ' ' <<  s.substr(1) << endl;
        return;
    }else if(s[0] < s[1]){
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << s[0] << ' ' << s[1] << endl;
        return;
    }
    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}