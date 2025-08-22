#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    ll n; cin >> n;
    vector<int> A(n), B(n);
    for(auto &a : A) cin >> a;
    for(auto &b : B) cin >> b;

    ll min_a = *min_element(all(A));
    ll min_b = *min_element(all(B));
    ll sum_a = accumulate(all(A), 0ll);
    ll sum_b = accumulate(all(B), 0ll);

    cout << min(min_a*n + sum_b, min_b*n + sum_a) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}