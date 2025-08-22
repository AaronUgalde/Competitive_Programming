#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

struct range{
    int lo;
    int hi;
};

bool merge_ranges(range &a, range &b){
    if(b.lo > a.hi || b.hi < a.lo) return false;
    a.hi = min(a.hi, b.hi);
    a.lo = max(a.lo, b.lo);
    return true;
}

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    const int INF = 1e9;

    range ans = {0, INF};
    for(int i = 0; i<n-1; i++){
        range current;
        if(A[i] < A[i+1]){
            current = {0, (A[i+1]-A[i])/2 + A[i]};
        }else if(A[i] > A[i+1]){
            current = {(A[i] - A[i+1] + 1)/2 + A[i+1], INF};
        }else{
            current = {0, INF};
        }
        if(!merge_ranges(ans, current)){
            cout << -1 << endl;
            return;
        }
        //cout << ans.lo << ' ' << ans.hi << endl;
    }

    cout << ans.lo << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}