#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())


void solve(int testcase){
    int n, x; cin >> n >> x;
    vector<pair<int, int>> A(n);
    for(int i = 0; i<n; i++){
        cin >> A[i].first;
        A[i].second = 1;
    }
    
    int i = 0;
    ll ans = 0;
    for(auto &a : A) ans += a.first;

    while(i < sz(A)){
        if(A[i].first % x == 0){
            ans += A[i].first * A[i].second;
            A.emplace_back(A[i].first/x, A[i].second*x);
        }else{
            break;
        }
        i++;
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}