#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    string n; cin >> n;
    cout << (n.size() > 1 && n[0] == '1' && n[n.size()-1] != '9'  && (count(all(n), '0') == 0 || (count(all(n), '0') == 1 && n[n.size()-1] == '0'))? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}