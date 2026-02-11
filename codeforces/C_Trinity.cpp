#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;
    sort(all(A));

    int mn = 0, mx = n - 1;
    int j = -1;
    int mn_cnt = INT_MAX;
    for(int i = 0; i < n - 1; i++){
        while(j + 1 < n and A[i] + A[i + 1] > A[j + 1]){
            j++;
        }
        mn_cnt = min(mn_cnt, n - (j - i + 1));
    }

    cout << mn_cnt << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}