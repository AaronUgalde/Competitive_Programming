#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')
#define _USE_MATH_DEFINES

const double PI = numbers::pi;

void solve(int testcase){
    double n; cin >> n;
    n *= 2;
    double sin_a = sin(2 * PI / n);
    double sin_b = sin((PI / 2) - (PI / n));
    cout << fixed << setprecision(9);
    double B = sin_b / sin_a;
    double x = sqrt(B * B - 0.5 * 0.5);
    cout << 2 * x << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}