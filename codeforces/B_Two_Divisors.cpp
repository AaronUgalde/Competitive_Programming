#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int a, b; cin >> a >> b;
    if(a == 1){
        cout << b*b;
    }else if(gcd(a, b) == 1){
        cout << a*b;
    }else{
        cout << b*(b/gcd(a, b));
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}