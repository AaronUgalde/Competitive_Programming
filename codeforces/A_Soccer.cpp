#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int x1, y1; cin >> x1 >> y1;
    int x2, y2; cin >> x2 >> y2;
    char first_max = (x1 > y1 ? 'x' : 'y');
    char second_max = (x2 > y2 ? 'x' : 'y');
    cout << (first_max == second_max ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}