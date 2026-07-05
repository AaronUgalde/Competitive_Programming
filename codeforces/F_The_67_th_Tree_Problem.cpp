#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int even, odd;
    cin >> even >> odd;

    if((even + odd) % 2 == 0){
        even--;
    }else{
        odd--;
    }

    if(min(even, odd) < 0 || even > odd){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    int current = 2;
    for(int i = 0; i < even; i++, current += 2, odd--){
        cout << current << ' ' << current + 1 << endl;
        cout << 1 << ' ' << current << endl;
    }

    for(int i = 0; i < odd; i++, current++){
        cout << 1 << ' ' << current << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}