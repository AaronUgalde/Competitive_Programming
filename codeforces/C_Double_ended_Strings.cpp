#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    string a, b;
	cin >> a >> b;

	int max_coincidences = INT_MIN;
	for(int i = -sz(b) + 1; i < sz(a); i++){
		int coincidences = 0;
		bool started = false;
		for(int j = 0; j < sz(b); j++){
			if(j + i < sz(a) && i + j >= 0 && a[j + i] == b[j]) coincidences++, started = true;
			else if(started) max_coincidences = max(max_coincidences, coincidences), coincidences = 0, started = false;
		}
		max_coincidences = max(coincidences, max_coincidences);
	}

	cout << sz(a) + sz(b) - 2 * max_coincidences << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}