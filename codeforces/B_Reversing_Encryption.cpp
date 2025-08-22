#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0; i<n; i++){
        if(n % (i + 1) == 0){
            reverse(s.begin(), s.begin()+i+1);
        }
    }
    cout << s << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}