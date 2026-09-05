#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    string L, R;   
    cin >> L >> R;
    reverse(all(L)); reverse(all(R));
    while(sz(L) < sz(R)) L += '0';
    
    int i = sz(R) - 1; 
    for(; i >= 0 and R[i] == L[i]; i--);
    i = max(0, i);

    cout << R[i] - L[i] + i * 9 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}