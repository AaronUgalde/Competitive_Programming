#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    int ans = 0;
    while(n >= 2){
        int cards_needed = 2;
        int h = 1;
        while((cards_needed + 3 * (h + 1) - 1) <= n){
            cards_needed += 3 * (h + 1) - 1;
            h++;
        }
        n -= cards_needed;
        ans++;
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}