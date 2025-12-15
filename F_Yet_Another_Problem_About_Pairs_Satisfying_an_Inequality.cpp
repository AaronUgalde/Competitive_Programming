#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    ll n; cin >> n;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    vector<pair<ll, ll>> a_i;
    for(int i = 0; i < n; i++){
        if(A[i] < i + 1) a_i.emplace_back(A[i], i + 1);
    }

    vector<pair<ll, ll>> a_j;
    for(int j = 0; j < n; j++){
        if(A[j] < j + 1) a_j.emplace_back(A[j], j + 1);
    }

    sort(all(a_j));

    ll ans = 0;
    ll cnt = 0;
    ll j = 0;
    for(int i = 0; i < sz(a_i); i++){
        if(j < sz(a_j) and a_i[i].second < a_j[j].first) cnt++;
        else{
            while(j < sz(a_j) and a_i[i].second >= a_j[j].first){
                ans += cnt;
                j++;
            }
            if(j < sz(a_j)) cnt++;
        }
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