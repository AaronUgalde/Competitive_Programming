#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<int> A(n), B(m);
    for(auto &a : A) cin >> a;
    for(auto &b : B) cin >> b;

    reverse(all(A));

    map<int, int> present_index;
    for(int i = 0; i<n; i++){
        present_index[A[i]] = i;
    }

    ll moves = 0;
    int last_reordered = n-1;
    for(int i = 0; i<m; i++){
        if(present_index[B[i]] >= last_reordered) moves++;
        else{
            moves += (n - present_index[B[i]] - 1) * 2 + 1;
            last_reordered = present_index[B[i]];
        }
        n--;
    }

    cout << moves << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}