#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, k; cin >> n >> k;
    vector<pair<int, int>> health_mod(n);
    for(int i = 0; i<n; i++){
        int health; cin >> health;
        health_mod[i].first = (health % k == 0 ? k : health % k);
        health_mod[i].second = -i;
    }

    sort(all(health_mod));

    for(int i = n-1; i>=0; i--){
        cout << -health_mod[i].second + 1<< ' ';
    }

    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}