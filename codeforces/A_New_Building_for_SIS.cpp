#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, h, a, b, k; cin >> n >> h >> a >> b >> k;
    for(int i = 0; i<k; i++){
        int t_a, f_a, t_b, f_b; cin >> t_a >> f_a >> t_b >> f_b;
        int ans = 0;
        if(t_a == t_b){
            cout << abs(f_a-f_b) << endl;
            continue;
        }
        if(f_a > b && f_b > b) ans += f_a - b, f_a = b;
        else if(f_a < a && f_b < a) ans += a - f_a, f_a = a;
        ans += abs(f_a - f_b) + abs(t_a-t_b);
        cout << ans << endl;
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