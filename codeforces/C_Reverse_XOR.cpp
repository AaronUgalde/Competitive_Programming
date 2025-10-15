#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    unsigned long long n; cin >> n;
	bitset<30> b_n(n);
	int i = 29, j = 0;
	while(i >= 0 && b_n[i] == 0) i--;
	while(j < 30 && b_n[j] == 0) j++;
	if((i == j && b_n[i] == 1) or (b_n.count() % 2 != 0)){
		cout << "NO" << endl;
		return;
	}

	while(i > j){
		i--; j++;
		if((b_n[i] == 1 && b_n[j] == 0) or (b_n[i] == 0 && b_n[j] == 1)){
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}