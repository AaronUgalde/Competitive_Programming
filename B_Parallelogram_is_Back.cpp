#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

struct Point {
    int x, y;
    Point operator+(const Point& other) const {
        return {x + other.x, y + other.y};
    }
    Point operator-(const Point& other) const {
        return {x - other.x, y - other.y};
    }
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

void solve(int testcase){
    vector<Point> p(3);
    for (int i = 0; i < 3; ++i) cin >> p[i].x >> p[i].y;
    
    set<Point> possibles;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            int k = 3 - i - j;
            Point diff = p[i] - p[j];
            possibles.insert(p[k] + diff);  
            possibles.insert(p[k] - diff);
        }
    }

    cout << possibles.size() << "\n";
    for (const Point &pt : possibles) {
        cout << pt.x << " " << pt.y << "\n";
    }

    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}