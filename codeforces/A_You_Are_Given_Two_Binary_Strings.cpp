#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    string x, y; cin >> x >> y;
    reverse(all(x));
    reverse(all(y));
    int first_one_y = 0;
    for(int i = 0; i<y.size(); i++){
        if(y[i] == '1'){
            first_one_y = i;
            break;
        }
    }

    int first_reachable_one_x = first_one_y;
    for(int i = first_one_y; i<x.size(); i++){
        if(x[i] == '1'){
            first_reachable_one_x = i;
            break;
        }
    }

    println("{}", first_reachable_one_x - first_one_y);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}