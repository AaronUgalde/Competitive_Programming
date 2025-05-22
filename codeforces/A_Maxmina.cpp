#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n);
    bool one = false;
    for(auto &x : a){
        cin >> x;
        if(x == 1){
            one = true;
        }
    }

    cout << (one ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}