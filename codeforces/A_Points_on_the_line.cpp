#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, d; cin >> n >> d;
    vector<int> X(n);
    for(auto &x : X) cin >> x;
    sort(all(X));
    
    if(n == 1){
        cout << 0 << endl;
        return;
    }

    int D = X[n - 1] - X[0];
    n--;
    vector<int> diff(n);
    for(int i = 0; i < n; i++){
        diff[i] = X[i + 1] - X[i];
    }

    vector<int> prefix(n + 1, 0);
    vector<int> suffix(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefix[i + 1] += prefix[i] + diff[i];
        suffix[n - 1 - i] += suffix[n - i] + diff[n - 1 - i];
    }
    
    int min_deletions = INT_MAX;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(D - prefix[i] - suffix[j] <= d){
                min_deletions = min(min_deletions, i + n - j);
            }
        }
    }

    cout << min_deletions << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}