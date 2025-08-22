#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    ll n; cin >> n;
    vector<ll> A(n);
    for(auto &a : A) cin >>a;

    map<ll, vector<ll>> adj;
    set<ll> visited;
    for(int i = 0; i<n; i++){
        adj[i + A[i]].push_back((i + A[i]) + i);
    }

    ll max_size = sz(A);
    auto dfs = [&](auto &&self, ll start) -> void {
        visited.insert(start);
        max_size = max(max_size, start);
        for(auto &neighbour : adj[start]){
            if(!visited.contains(neighbour)){
                self(self, neighbour);
            }
        }
    };
    
    dfs(dfs, sz(A));

    cout << max_size << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}