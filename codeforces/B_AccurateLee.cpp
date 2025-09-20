#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;
    int i = -1, j = n;
    while(i + 1 < n && s[i + 1] == '0') i++;
    while(j - 1 >= 0 && s[j - 1] == '1') j--;
    if(j == i + 1){
        cout << s << endl;
        return;
    }

    else cout << s.substr(0, i + 1) << 0 << s.substr(j) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}