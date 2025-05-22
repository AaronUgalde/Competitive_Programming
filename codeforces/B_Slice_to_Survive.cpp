#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int ans(int n, int m){
    int cnt = 0;
    while(n > 1){
        n -= (n/2);
        cnt++;
    }
    while(m > 1){
        m -= (m/2);
        cnt++;
    }
    return cnt;
}

void solve(int testcase){
    int n, m, a, b; cin >> n >> m >> a >> b;
    int ans_a = min(ans(a, m), ans(n-a+1, m));
    int ans_b = min(ans(n, b), ans(n, m-b+1));

    cout << min(ans_a, ans_b) + 1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}