#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())



void solve(int testcase){
    ll ax, ay, bx, by, cx, cy; cin >> ax >> ay >> bx >> by >> cx >> cy;

    auto dist_square = [&](ll x, ll y, ll a, ll b){
        return (x-a) * (x-a) + (y-b) * (y-b); 
    };

    if(dist_square(ax, ay, bx, by) == dist_square(cx, cy, bx, by) && dist_square(cx, cy, ax, ay) != 4*dist_square(ax, ay, bx, by)) cout << "Yes" << endl;
    else cout << "No" << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}