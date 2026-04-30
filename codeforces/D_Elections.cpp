#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n, c; cin >> n >> c;
    vector<pair<ll, ll>> A(n);
    vector<ll> prefix(n + 1);
    for(int i = 0; i < n; i++){
        cin >> A[i].first;
        A[i].second = i;
        prefix[i + 1] = prefix[i] + A[i].first;
    }

    ll first = A[0].first + c;
    sort(all(A));
    bool more_winners = false;
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        if(A[i].first == A[n - 1].first){
            if(A[i].first > first and !more_winners){
                ans[A[i].second] = 0;
            }else{
                ans[A[i].second] = A[i].second;
            }
            more_winners = true;
        }else if(A[i].first + prefix[A[i].second] + c >= A[n - 1].first){
            ans[A[i].second] = A[i].second;
        }else{
            ans[A[i].second] = A[i].second + 1;
        }
    }

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