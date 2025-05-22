#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, m, q; cin >> n >> m >> q;
    int t1, t2; cin >> t1 >> t2; t1--; t2--;
    int d; cin >> d; d--;
    int d_t1 = abs(d - t1);
    int d_t2 = abs(d - t2);
    if(d < t2 && d < t1){
        cout << d + abs(min(t1, t2) - d) << endl;
    }else if(d > t2 && d > t1){
        cout << (n-1-d) + abs(max(t1, t2) - d) << endl;
    }else{
        cout << min(d_t1, d_t2) + (max(d_t1, d_t2) - min(d_t1, d_t2))/2 << endl;
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