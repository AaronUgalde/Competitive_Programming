#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    sort(all(a));
    if((a[0] + a[n-1]) % 2 == 0){
        cout << 0 << endl;
        return;
    }

    int i = 0;
    int operations_a = 0;
    while((a[i] + a[n-1])%2 != 0){
        i++;
        operations_a++;
    }

    i = n-1;
    int operations_b = 0;
    while((a[i] + a[0])%2 != 0){
        i--;
        operations_b++;
    }

    cout << min(operations_a, operations_b) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}