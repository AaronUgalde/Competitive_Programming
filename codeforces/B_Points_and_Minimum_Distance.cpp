#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

struct Point{
    int x;
    int y;
};

int manhattanDist(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void solve(int testcase){
    int n; cin >> n;
    vector<int> coordinates(2*n);
    for(int i = 0; i<2*n; i++){
        cin >> coordinates[i];
    }
    sort(all(coordinates));
    int x = 1, y = 2*n-2;
    int s = 0;
    Point last = {coordinates[0], coordinates[2*n-1]};
    vector<Point> points;
    points.push_back(last);
    while(x < n){
        Point current = {coordinates[x], coordinates[y]};
        s += manhattanDist(last, current);
        last = current;
        x++; y--;
        points.push_back(current);
    }

    cout << s << endl;
    for(int i = 0; i<n; i++){
        cout << points[i].x << ' ' << points[i].y << endl;
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