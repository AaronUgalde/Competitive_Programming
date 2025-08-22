#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> P(n);
    for(auto &p : P) cin >> p, p--;

    for(int i = 0; i<n; i++){
        set<int> visited;
        visited.insert(i);
        int current = P[i];
        while(!visited.count(current)){
            visited.insert(current);
            current = P[current];
        }
        cout << current + 1 << ' ';
    }

    cout << endl; 
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}