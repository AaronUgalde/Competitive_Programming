#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

struct Point {
    double x, y;
    // Sobrecarga de operador< usando atan2 (fácil de entender, pero algo más lenta)
    bool operator<(const Point& other) const {
        double a1 = atan2(y, x);
        double a2 = atan2(other.y, other.x);
        return a1 < a2;
    }
};

double angleDot(const Point& A, const Point& B) {
    // producto punto
    double dot = A.x*B.x + A.y*B.y;
    // magnitudes
    double magA = hypot(A.x, A.y);
    double magB = hypot(B.x, B.y);
    // asegura dominio válido para acos
    double c = dot / (magA * magB);
    if (c >  1) c =  1;
    if (c < -1) c = -1;
    return acos(c);  // en radianes
}

void solve(int testcase){
    int n; cin >> n;
    vector<pair<Point, int>> points(n);
    for(int i = 0; i<n; i++){
        cin >> points[i].first.x >> points[i].first.y;
        points[i].second = i;
    }

    sort(all(points));
    double minAngle = INT_MAX;
    pair<int, int> minIndices;
    for(int i = 0; i<n; i++){
        double angle = angleDot(points[i].first, points[(i+1)%n].first);
        if(angle < minAngle){
            minAngle = angle;
            minIndices.first = points[i].second;
            minIndices.second = points[(i + 1)%n].second;
        }
    }

    cout << minIndices.first + 1 << ' ' << minIndices.second + 1 << endl; 
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}