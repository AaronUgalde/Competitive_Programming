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
	vector<int> A(n);
	for(auto &a : A) cin >> a;

	if(A[0] != n and A[n - 1] != n){
		cout << -1 << endl;
		return;
	}

	reverse(all(A));
	for(auto &a : A) if(a != n) cout << a << ' ';
	cout << n << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}