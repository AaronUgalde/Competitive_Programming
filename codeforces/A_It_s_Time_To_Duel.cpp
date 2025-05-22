#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x; 

    bool zero = false;
    for(int i = 0; i<n-1; i++){
        if(a[i] == 0 || a[i+1] == 0){
            zero = true;
            if(a[i] == 0 && a[i+1] == 0){
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << (zero ? "NO" : "YES") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}