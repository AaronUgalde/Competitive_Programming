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
	string s; cin >> s;
	int q; cin >> q;
	vector<ll> A(q);
	vector<ll> B(q);

	ll plus = 0;
	ll minus = 0;
	for(auto &c : s){
		if(c == '-') minus++;
		else plus++;
	}

	ll op_min = min(plus, minus);
	ll op_max = max(plus, minus);

	for(int i = 0; i < q; i++){
		cin >> A[i];
		cin >> B[i];
		ll a = min(A[i], B[i]);
		ll b = max(A[i], B[i]);
		ll diff = (op_max - op_min);
		if(diff == 0){
			cout << "YES" << endl;
			continue;
		}else if(a == b){
			cout << "NO" << endl;
			continue;
		}
		ll same = (a * diff) / (b - a);
		if(same <= op_min and (a * diff) % (b - a) == 0){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
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