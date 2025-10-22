#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, m; cin >> n >> m;
	vector<string> grid(n);
	for(auto &s : grid) cin >> s;

	vector<int> floor_per_column(m, n - 1);
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == '*'){
				grid[i][j] = '.';
				grid[floor_per_column[j]][j] = '*';
				floor_per_column[j]--;
			}else if(grid[i][j] == 'o'){
				floor_per_column[j] = i - 1;
			}
			
		}

	}

	for(auto &s : grid){
		cout << s << endl;
	}
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