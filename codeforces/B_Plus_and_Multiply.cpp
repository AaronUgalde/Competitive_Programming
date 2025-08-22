#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    ll n, a, b; cin >> n >> a >> b;

    if(n == 1 || b == 1){
        cout << "Yes" << endl;
        return;
    }

    ll curr = 1;
    while((n - curr) % b != 0 && curr < n && a != 1){
        curr *= a;
    }

    if(n == curr){
        cout << "Yes" << endl;
        return;
    }

    if((n-curr) % b == 0 && curr < n){
        cout << "Yes" << endl;
        return;
    }

    cout << "No" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}