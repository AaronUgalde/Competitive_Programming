#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

vector<int> damage = {1, 1, 3};

void solve(int testcase){
    int n; cin >> n;
    vector<ll> healths(n);
    for(auto &health : healths) cin >> health;

    ll t = 0; 
    int i = 0;
    for(auto &health : healths){
        ll div = health / 5;
        ll rem = health % 5;
        t += div * 3;
        while(rem > 0){
            rem -= damage[i];
            i = (i + 1) % 3;
            t++;
        }
    }

    cout << t << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}