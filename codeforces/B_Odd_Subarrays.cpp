#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> p(n);
    for(auto &x : p){
        cin >> x;
        x--;
    };

    int ans_a = 0;
    for(int i = 0; i<n-1; i++){
        if(p[i] > p[i+1]) ans_a++, i++;
    }

    cout << ans_a << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}