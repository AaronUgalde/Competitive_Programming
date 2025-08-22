#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    vector<ll> meals(3);
    cin >> meals[0] >> meals[1] >> meals[2];
    sort(all(meals));

    ll total = 2*meals[2] - meals[1] - meals[0];
    if(meals[2] > meals[1] && meals[2] > meals[0]) total -= 2;
    else if(meals[2] > meals[1] ^ meals[2] > meals[0]) total--;
    cout << total << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}