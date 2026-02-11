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
    map<int, int> mp;
    for(auto &a : A) cin >> a, mp[a]++;

    sort(all(A));

    if(A[0] == A[n - 1]){
        cout << n / 2 << endl;
        return;
    }

    ll mx = INT_MIN;
    for(ll i = 0, j = 0; i < n; i = j = j + 1){
        while(j < n - 1 and A[i] == A[j + 1]){
            j++;
        }
        mx = max(mx, (n - (j + 1)) * (j + 1));
    }
    

    cout << mx << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}