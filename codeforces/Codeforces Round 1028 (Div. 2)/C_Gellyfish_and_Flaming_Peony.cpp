#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    sort(all(a));
    int all_gcd = a[0];
    for(int i = 1; i<n; i++){
        all_gcd = gcd(all_gcd, a[i]);
    }

    int i, j;
    int mn_gcd = a[0];
    for(i = 0; i<n; i++){
        for(j = i + 1; i<n; i++){
            
        }
    }
    
    for(int i = 0; i<n; i++){
        if(a[i] <= all_gcd) continue;
        op++;
    }

    cout << op << endl; 
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}