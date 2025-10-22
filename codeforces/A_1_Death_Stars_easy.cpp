#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

struct p{
	int x;
	int y;
	bool operator==(const p &b) const{
		return (x == b.x && y == b.y);
	}
};

p rotate_90(p point, int n){
	return{point.y, (n - 1) - point.x};
}

p flip_vert(p point, int n){
	return{point.x, (n - 1) - point.y};
}


p flip_hort(p point, int n){
	return{(n - 1) - point.x, point.y};
}

p equal_point(p point, int n){
	return point;
}

bool check(vector<string> &grid_1, vector<string> &grid_2, int n, function<p(p, int)> axis){
	for(int rot = 0; rot < 4; rot++){
		int x, y;
		for(x = 0; x < n; x++){
			for(y = 0; y < n; y++){
				p point = {x, y};
				p rot_point = point;
				rot_point = axis(rot_point, n);
				for(int i = 0; i < rot; i++) rot_point = rotate_90(rot_point, n); 
				if(grid_1[point.x][point.y] != grid_2[rot_point.x][rot_point.y]) goto next_rotation;
			}
		}
		return true;
		next_rotation:
		;
	}
	return false;
}

void solve(int testcase){
	int n; cin >> n;
	vector<string> grid_1(n);
	vector<string> grid_2(n);
	for(auto &s : grid_1) cin >> s;
	for(auto &s : grid_2) cin >> s;

	vector<p(*)(p, int)> axis = {flip_vert, flip_hort, equal_point};
	for(auto &a : axis){
		if(check(grid_1, grid_2, n, a)){
			cout << "Yes" << endl;
			return;
		}
	}

	cout << "No" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}