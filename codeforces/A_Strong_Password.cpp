#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    string s; cin >> s;
    int i = 0;
    for(; i<s.size()-1; i++){
        if(s[i] == s[i+1]) break;
    }

    char a = 'a', b = 'b';
    s.insert(i+1, 1, (s[i] == a ? b : a));
    cout << s << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}