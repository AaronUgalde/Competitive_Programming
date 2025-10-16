#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    ull x, y, z; cin >> x >> y >> z;
    const int N = 62;
    bitset<N> b(x), c(y), d(z), a;
    for(int i = 0; i < N; i++){
        if((b[i] && !c[i] && !d[i]) || (!b[i] && c[i] && d[i])){
            cout << -1 << endl;
            return;
        }
        if(b[i] && c[i]){
            a[i] = !d[i];
        }else{
            a[i] = d[i];
        }
    }

    cout << a.to_ullong() << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}