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
    
    if(even > odd){
        cout << "NO" << endl;
        return;
    }

    if(even == 0){
        if(odd % 2 == 0){
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        for(int i = 2; i <= odd; i++){
            cout << 1 << ' ' << i << endl;
        }
        return;
    }

    cout << "YES" << endl;
    int i = 2;
    if((odd - even) % 2 == 0){
        cout << 1 << ' ' << 2 << endl;
        even--;
        i++;
    }

    odd--;
    while(even > 0){
        cout << i << ' ' << i + 1 << endl;
        cout << 1 << ' ' << i << endl;
        even--;
        odd--;
        i += 2;
    }

    while(odd > 0){
        cout << 1 << ' ' << i << endl;
        odd--;
        i++;
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