#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

int layers(int a, int b){
    int layers = 1;
    int k = 1;
    while(k <= (layers % 2 == 0 ? a : b)){
        (layers % 2 == 0 ? a : b) -= k;
        layers++;
        k *= 2;
    }
    return layers - 1;
}

void solve(int testcase){
    int a, b; cin >> a >> b;
    cout << max(layers(a, b), layers(b, a)) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}