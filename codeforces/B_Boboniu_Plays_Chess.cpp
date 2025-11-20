#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, m; cin >> n >> m;
    int s_x, s_y; cin >> s_x >> s_y;
    int e_x = 1, e_y = s_y;
    cout << s_x << ' ' << s_y << endl;
    cout << e_x << ' ' << e_y << endl;

    for(int x = 1; x <= n; x++){
        for(int y = 1; y <= m; y++){
            int r_y = y;
            if(x % 2 == 1){
                r_y = m + 1 - y;
            }
            if((x == s_x and r_y == s_y) or (x == e_x and r_y == e_y)) continue;
            cout << x << ' ' << r_y << endl;
        }
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}