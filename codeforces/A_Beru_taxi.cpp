#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int a, b;

double dist (int x, int y){
    return(sqrt((a-x)*(a-x) + (b-y)*(b-y)));
}

double time(int x, int y, int v){
    return dist(x, y)/v;
}

void solve(int testcase){
    cin >> a >> b;
    int n; cin >> n;
    vector<int> x(n), y(n), v(n);
    for(int i = 0; i<n; i++){
        cin >> x[i] >> y[i] >> v[i];
    }

    double min_time = INT_MAX;
    for(int i = 0; i<n; i++){
        min_time = min(min_time, time(x[i], y[i], v[i]));
    }

    cout << setprecision(12) << fixed << min_time << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}