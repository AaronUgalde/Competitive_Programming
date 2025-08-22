#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    string a, b; cin >> a >> b;

    vector<ll> a_ops(n + 1, 0);
    vector<ll> b_ops(n + 1, 0);
    for(int i = 0; i<n; i++){
        a_ops[i + 1] = a_ops[i] + (a[i] != b[i]);
        b_ops[i + 1] = b_ops[i] + (b[i] != a[i]);
    }

    ll sum = 0;
    ll sum_b = accumulate(all(b_ops), 0ll);
    for(int i = 0; i<n; i++){
        sum += b_ops[i + 1] * n;
        cout << "i: " << i << " " << a_ops[i + 1] * n + sum_b << endl;
    }

    cout << sum_b << endl;
    cout << sum << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}