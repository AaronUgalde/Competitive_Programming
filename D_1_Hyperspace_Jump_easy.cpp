#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int m; cin >> m;
    vector<pair<int, int>> ship_coordinate(m);
    map<pair<int, int>, int> coordinate_ships;
    for(int i = 0; i < m; i++){
        string s; cin >> s; 
        int pos_plus = (s[2] == '+' ? 2 : 3);
        string a_s = s.substr(1, pos_plus - 1);
        int a = stoi(a_s);
        int pos_divide = (s[pos_plus + 2] == ')' ? pos_plus + 3: pos_plus + 4);
        string b_s = s.substr(pos_plus + 1, (pos_divide == pos_plus + 3 ? 1 : 2));
        int b = stoi(b_s);
        string c_s = s.substr(pos_divide + 1);
        int c = stoi(c_s);
        int g = gcd(a + b, c);
        ship_coordinate[i] = {(a + b) / g, c / g};
        coordinate_ships[ship_coordinate[i]]++;
    }

    for(int i = 0; i < m; i++){
        cout << coordinate_ships[ship_coordinate[i]] << ' ';
    }

    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}