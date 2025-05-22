#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;

    bool valley = false;
    bool start = false;
    for(int i = 0; i<n; i++){
        if((i == n - 1 || a[i+1] > a[i])){
            valley = true;
        }else if(valley && a[i+1] < a[i]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}