#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, s; cin >> n >> s;
    if(s/n <= 1){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    int d = s/n;
    for(int i = 0; i<n-1; i++){
        cout << d << ' ';
    }

    cout << d+s%n << endl << 1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}