#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    string a, b; cin >> a >> b;
    
    int ones_mod_0 = 0, ones_mod_1 = 0;
    int zeros_mod_0 = 0, zeros_mod_1 = 0;
    for(int i = 0; i<n; i++){
        if(i % 2 == 0){
            ones_mod_0 += (a[i] == '1');
            zeros_mod_0 += (b[i] == '0');
        }else{
            ones_mod_1 += (a[i] == '1');
            zeros_mod_1 += (b[i] == '0');
        }
    }

    cout << (zeros_mod_0 >= ones_mod_1 && zeros_mod_1  >= ones_mod_0 ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}