#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, k; cin >> n >> k;
	string s; cin >> s;
	
	for(int i = 0; i <= k and i < n; i++){
		if(s[n - 1 - i] == '1'){
			if(i > 0){
				swap(s[n - 1 - i], s[n - 1]);
				k -= i;
			}
			break;
		}
	}

	for(int i = 0; i <= k and i < n; i++){
		if(s[i] == '1'){
			if(i > 0 and i != n - 1){
				swap(s[0], s[i]);
				k -= i;
			}
			break;
		}
	}

	
	ll sum = 0;
	for(int i = 0; i < n - 1; i++){
		sum += stoi(s.substr(i, 2));
	}

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