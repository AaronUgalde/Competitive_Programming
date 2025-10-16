#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
	set<int> A;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		A.insert(x);
	}

	if(sz(A) > 3){
		cout << -1 << endl;
		return;
	}

	if(sz(A) == 2){
		cout << ((*next(A.begin(), 1) - *A.begin()) % 2 == 0 ? (*next(A.begin(), 1) - *A.begin()) / 2 : *next(A.begin(), 1) - *A.begin()) << endl;
		return;
	}

	if(sz(A) == 1){
		cout << 0 << endl;
		return;
	}

	if(*next(A.begin(), 1) - *A.begin() == *next(A.begin(), 2) - *next(A.begin(), 1)){
		cout << *next(A.begin(), 1) - *A.begin() << endl;
		return;
	}

	cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}