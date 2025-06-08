#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

struct Point{
    long double x;
    long double y;
};

long double dist(Point a, Point b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void solve(int testcase){
    Point p; cin >> p.x >> p.y;
    Point a; cin >> a.x >> a.y;
    Point b; cin >> b.x >> b.y;
    Point o; o.x = 0; o.y = 0;

    long double r = 0;
    
    if(dist(a, o) > dist(b, o)) swap(a, b);
    if (dist(a,p) < dist(b, p)) b = a;

    if(dist(o, a) >= dist(p, b) && dist(o, a) >= dist(a, b)/2) r = dist(o, a);
    else if(dist(p, b) >= dist(o, a) && dist(p, b) >= dist(a, b)/2) r = dist(p, b);
    else r = dist(a, b)/2;

    cout << setprecision(10) << fixed << r << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}