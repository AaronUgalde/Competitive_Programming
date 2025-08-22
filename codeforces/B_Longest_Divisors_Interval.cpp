#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    /*
        Para todo intervalor [l, r] valido, donde L = r - l + 1, existe un x, tal que x >= 1 && x <= L && x | n
        ya que, si x <= L el 0 pertenece al conjunto de numeros {l mod x, l+1 mod x, ..., r mod x}
        por lo tanto es suficiente con encontrar el mayor intervalor [1, L]
    */
    ll n; cin >> n;
    ll x = 1;
    while(n % x == 0) x++;
    cout << (x - 1) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}