#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n, k; cin >> n >> k;
    set<int> A;
    for(int i = 0; i< n; i++){
        int a; cin >> a;
        A.insert(a);
    }

    set<int> ans;
    set<int> visited;
    for(auto &a : A){
        if(visited.count(a)) continue;
        ans.insert(a);
        for(int i = 1; i * a <= k; i++){
            if(!A.count(i * a)){
                cout << -1 << endl;
                return;
            }
            visited.insert(i * a);
        }
    }

    cout << sz(ans) << endl;
    for(auto &a : ans) cout << a << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}