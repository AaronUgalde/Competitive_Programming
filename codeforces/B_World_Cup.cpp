#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, a, b; cin >> n >> a >> b;
	int t = a;
	a = min(t, b);
	b = max(t, b);
	int round = 1;
	while(a % 2 != 1 or (a + 1) != b){
		round++;
		a = (a + 1) / 2;
		b = (b + 1) / 2;
	}

	if(round == log2(n)) cout << "Final!" << endl;
	else cout << round << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}