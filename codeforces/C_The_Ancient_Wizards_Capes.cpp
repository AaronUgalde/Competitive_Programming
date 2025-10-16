#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
	vector<int> A(n);
	for(auto &a : A) cin >> a;
	int ans = 0;
	for(int first = 0; first < 2; first++){
		bool is_valid = true;
		vector<int> config(n);
		config[0] = first;
		for(int i = 1; i < n; i++){
			int diff = abs(A[i] - A[i - 1]);
			if(diff > 1) {
				is_valid = false;
			}
			else if(diff == 0){
				config[i] = 1 - config[i - 1];
			}else{
				config[i] = config[i - 1];
			}
		}

		if(!is_valid) continue;

		int cnt = 1 + accumulate(config.begin() + 1, config.end(), 0);
		bool all_ok = A[0] == cnt;
		for(int i = 1; i < n; i++){
			if(config[i - 1] == 1) cnt--;
			if(config[i] == 0) cnt++;
			if(A[i] != cnt) {
				all_ok = false;
			}
		}
		if(all_ok) ans++;
	}

	cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}
