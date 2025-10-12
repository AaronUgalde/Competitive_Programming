#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    ll n; cin >> n;
	vector<ll> B(n);
	for(auto &b : B) cin >> b;

	ll diff = 1;
	vector<ll> config(n);
	config[0] = 1;
	for(int i = 1; i < n; i++){
		if(i - (B[i] - B[i - 1]) < 0){
			config[i] = i + 1;
		}else{
			config[i] = config[i - (B[i] - B[i - 1])];
		}
	}

	for(auto &c : config) cout << c << ' '; 
	cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}