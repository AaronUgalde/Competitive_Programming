#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    double sum = 0;
    while(n){
        sum += 1.0/n;
        n--;
    }
    cout << fixed << setprecision(12) << sum << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
  //  cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}