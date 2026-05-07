#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

bool prime(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }

    return true;
}

void solve(){
    int n; cin >> n;

    if(prime(n)){
        cout << 1 << endl;
    } else if(n % 2 == 0 or prime(n - 2)){
        cout << 2 << endl;
    }else{
        cout << 3 << endl;
    }
}   

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}