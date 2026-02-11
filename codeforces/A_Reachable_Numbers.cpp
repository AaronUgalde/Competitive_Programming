#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;

    int cnt = 0;
    set<int> appeard;
    while(!appeard.count(n)){
        appeard.insert(n);
        n += 1;
        cnt++;
        while(n % 10 == 0 and n != 0){
            n /= 10;
        }
    }

    cout << cnt << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}