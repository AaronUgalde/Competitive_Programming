#include <bits/stdc++.h>
#include <vector>
#define endl '\n'

using namespace std;

const long long MAX_N = 1e5+10;
vector<bool> visited(MAX_N, false);
vector<long long> adj[MAX_N];
long long dfs (long long node){
    visited[node] = true;
    long long cnt = 1;
    for(auto &v : adj[node]){
        if(!visited[v]){
            cnt += dfs(v);
        }
    }
    return cnt;
} 

long long nC2(long long n) {
    return n * (n - 1) / 2;
}

int main(){
    long long n, k; cin >> n >> k;
    for(int i = 0; i<k; i++){
        long long u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long p = 0;
    long long q = nC2(n);

    for(int i = 0; i<n; i++){
        if(!visited[i]){
            long long nodes = dfs(i);
            p += nC2(nodes);
        }
    }

    long long d = gcd(p, q);
    p /= d;
    q /= d;

    cout << p << ' ' << q << endl;
}