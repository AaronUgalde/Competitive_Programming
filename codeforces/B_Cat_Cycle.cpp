#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    // A - - B
    // - A B -

    // A - - - - B
    // - A - - B -

    // A - B
    // B A -
    // - B A
    // A - B

    // A - - - B 1
    // - A - B - 2
    // - B A - - 3
    // B - - A - 4
    // - - - B A 5
    // A - B - - 6
    // B A - - - 7
    // A - - - B 8

    // A - - - - - B
    int n, k; cin >> n >> k;
    if(n % 2 == 0){
        if(k % n == 0) cout << n << endl;
        else cout << k % n << endl;
    }else{
        cout << "caca" << endl;
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