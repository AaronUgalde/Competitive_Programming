#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    ll n; cin >> n;
    int ans;
    cout << "mul 9" << endl;
    cin >> ans;
    cout << "digit" << endl;
    cin >> ans;
    if(n != 9){
        cout << "add " <<  n-9 << endl;
        cin >> ans;
        cout << "!" << endl;
        cin >> ans;
    }
    if(!ans){
        cout << "digit" << endl;
        cin >> ans;
        if(n != 9){
            cout << "add " <<  n-9 << endl;
            cin >> ans;
        }
        cout << "!" << endl;
        cin >> ans;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}