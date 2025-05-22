#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> a(n);
    int odd = 0;
    for(auto &x : a){
        cin >> x;
        if(x % 2 != 0){
            odd++;
        }
    }

    cout << (odd%2 == 0 ? "YES\n" : "NO\n");
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}