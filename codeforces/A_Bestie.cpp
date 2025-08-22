#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    int g = 0;
    for(int i = 0; i<n; i++){
        g = gcd(g, A[i]);
    }

    if(g == 1){
        cout << '0' << endl;
        return;
    }else if(gcd(g, n) == 1){
        cout << 1 << endl;
        return;
    }else if(gcd(g, n-1) == 1){
        cout << 2 << endl;
        return;
    }else{
        cout << 3 << endl;
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