#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, k; cin >> n >> k;
    if(n % 2 != 0)
        cout << n/2 << ' ' << n/2 << ' ' << 1 << endl;
    else if(n % 4 == 0){
        cout << n/2 << ' ' << n/4 << ' ' << n/4 << endl;
    }else{
        cout << 2 << ' ' << n/2 - 1 << ' ' << n/2 - 1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}