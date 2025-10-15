#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
	multiset<int> A;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		A.insert(x);
	}

	for(int i = 0; i <= 101; i++){
		if(!A.contains(i)){
			cout << i << endl;
			return;
		}
	}

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}