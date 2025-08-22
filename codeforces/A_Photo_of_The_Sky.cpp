#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<ll> A(2*n);
    for(auto &a : A) cin >> a;
    sort(all(A));
    if (n == 1){
		cout << "0";
		return;
	}
    ll min_y = LLONG_MAX;
    for(int i = 1; i<n; i++) min_y = min(min_y, A[i+n-1] - A[i]);
    cout << min((A[2*n-1] - A[0]) * min_y, (A[n-1] - A[0]) * (A[2*n - 1] - A[n])) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}